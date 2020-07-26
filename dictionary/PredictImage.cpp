#include<iostream>
#include<string>
// PATH in settings.json is /home/tlroot/installation/OpenCV-master/include/opencv4/
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/ml/ml.hpp>
// opencv2/nonfree/features2d.hpp is now called opencv2/xfeatures2d.hpp
// #include<opencv2/nonfree/features2d.hpp>
// #include<opencv2/nonfree/nonfree.hpp>
#include<opencv2/highgui/highgui.hpp>

// https://github.com/opencv/opencv_contrib/tree/master/modules/xfeatures2d/include/opencv2
#include<opencv2/xfeatures2d/nonfree.hpp>
// https://stackoverflow.com/questions/27418668/nonfree-module-is-missing-in-opencv-3-0
#include<opencv2/xfeatures2d.hpp>

using namespace std;
cv::Mat loadVocabulary(cv::Mat predictImage)
{
    cout<<"load vocabulary"<<endl;
    vector<cv::KeyPoint> predictKeypoint;
    cv::Mat predictImageDescriptor;
    cv::FileStorage fileStorage("dictionary.yml",cv::FileStorage::READ);
    cv::Mat vocabulary;
    fileStorage["vocabulary"]>>vocabulary;
    fileStorage.release();
    cv::Ptr<cv::FeatureDetector> siftFeatureDetector(new cv::SiftFeatureDetector(300));
    cv::Ptr<cv::DescriptorExtractor> siftDescriptorExtractor(new cv::SiftDescriptorExtractor);
    cv::Ptr<cv::DescriptorMatcher> flannBasedMatcher(new cv::FlannBasedMatcher);
    cv::BOWImgDescriptorExtractor bowImgDescriptorExtractor(siftDescriptorExtractor,flannBasedMatcher);
    bowImgDescriptorExtractor.setVocabulary(vocabulary);
    siftFeatureDetector->detect(predictImage,predictKeypoint);
    if(predictKeypoint.empty())
        cout<<"no keypoint "<<endl;
    bowImgDescriptorExtractor.compute(predictImage,predictKeypoint,predictImageDescriptor);
    cout<<"load vocabulary return"<<endl;
    if(predictImageDescriptor.empty())
        cout<<"the no descriptor extracted"<<endl;
    return predictImageDescriptor;

}

void predict(string imageName)
{
    cout<<"predict"<<endl;
    cv::Mat predictMat=cv::imread(imageName);
    if(predictMat.empty())
        cout<<"image is not read"<<endl;
    cv::SVM svm;
    svm.load("svmtrained.yml");
    cout<<"svm loaded successfully"<<endl;
    cv::Mat predictImageDescriptor=loadVocabulary(predictMat);
    int result=(int)svm.predict(predictImageDescriptor);
    
    if(result==1)
        cout<<"inputed Image is cat"<<endl;
    if(result==0)
        cout<<"inputed Image is dog"<<endl;
}
