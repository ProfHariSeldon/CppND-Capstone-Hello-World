#include <iostream>
#include"TrainSVM.h"
#include"PredictImage.hpp"
// PATH in settings.json is /home/tlroot/installation/OpenCV-master/include/opencv4/
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv2/opencv.hpp>
// opencv2/nonfree/features2d.hpp is now called opencv2/xfeatures2d.hpp
// #include<opencv2/nonfree/features2d.hpp>
#include<opencv2/features2d/features2d.hpp>

// https://stackoverflow.com/questions/27418668/nonfree-module-is-missing-in-opencv-3-0
#include<opencv2/xfeatures2d.hpp>

using namespace std;
using namespace cv;
int main()
{
    char * filename=new char[100];
    cv::Mat image;

    vector<cv::KeyPoint> keypoints;
    cv::Mat descriptor;
    cv::Mat unclusteredDescriptors;
    cv::SiftFeatureDetector sift(300);
    cv::SiftDescriptorExtractor siftDescriptorExtractor;
    for(int i=0; i<40; i++)
    {
        sprintf(filename,"images\\%i.jpg",i);
        image=cv::imread(filename,0);
        sift.detect(image,keypoints);
        siftDescriptorExtractor.compute(image,keypoints,descriptor);
        unclusteredDescriptors.push_back(descriptor);


    }

    int dictionarySize=200;
    cv::TermCriteria tc(cv::TermCriteria::COUNT,100,0.001);
//retries number
    int retries=1;
//necessary flags
    int flags=KMEANS_PP_CENTERS;
//Create the BoW (or BoF) trainer
    cv::BOWKMeansTrainer bowTrainer(dictionarySize,tc,retries,flags);
//cluster the feature vectors
    cv::Mat dictionary=bowTrainer.cluster(unclusteredDescriptors);
//store the vocabulary
    cv::FileStorage fs("dictionary.yml", cv::FileStorage::WRITE);
    fs << "vocabulary" << dictionary;
    fs.release();
    trainSVM();
    string predictImage="predictMe.jpg";
    predict(predictImage);


}
