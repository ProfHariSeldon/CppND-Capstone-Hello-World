
    #include "opencv2/opencv.hpp"
    #include "opencv2/dnn.hpp"
    
    using namespace cv;
    using namespace std;
    
    int main(int argc, char** argv)
    {
        vector<String> fn;
        // ORIGINAL CODE:
        // glob("c:/data/cat-dog/*.jpg", fn, true);
        // MY CODE:
        glob("/home/tlroot/Documents/C++/Capstone/OpenCVCNN/cat-dog/*.jpg", fn, true);
        // glob() will conveniently sort names lexically, so the cats come first!
        // so we have 700 cats, 699 dogs, and split it into:
        // 100 test cats
        // 600 train cats
        // 100 test dogs
        // 599 train dogs

        // ORIGINAL CODE:
        // std::string modelTxt = "c:/data/mdl/squeezenet/deploy.prototxt";
        // MY CODE:
        std::string modelTxt = "/home/tlroot/Documents/C++/Capstone/OpenCVCNN/squeezenet_v1.1.prototxt";
        // ORIGINAL CODE:
        // std::string modelBin = "c:/data/mdl/squeezenet/squeezenet_v1.1.caffemodel";
        // MY CODE:
        std::string modelBin = "/home/tlroot/Documents/C++/Capstone/OpenCVCNN/squeezenet_v1.1.caffemodel";
        dnn::Net net = dnn::readNetFromCaffe(modelTxt, modelBin);
        cv::Size inputImgSize = cv::Size(227, 227); // model was trained with this size
    
        Mat_<int> layers(4, 1);
        layers << 1000, 400, 100, 2; // the sqeezenet pool10 layer has 1000 neurons
    
        Ptr<ml::ANN_MLP> nn = ml::ANN_MLP::create();
        nn->setLayerSizes(layers);
        nn->setTrainMethod(ml::ANN_MLP::BACKPROP, 0.0001);
        nn->setActivationFunction(ml::ANN_MLP::SIGMOID_SYM);
        nn->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER+TermCriteria::EPS, 300, 0.0001));
    
        Mat train, test;
        Mat labels(1199, 2, CV_32F, 0.f); // 1399 - 200 test images
        for (size_t i=0; i<fn.size(); i++) {
            // use the dnn as a "fixed function" preprocessor (no training here)
            Mat img = imread(fn[i]);
            net.setInput(dnn::blobFromImage(img, 1, inputImgSize, Scalar::all(127), false));
            Mat blob = net.forward("pool10");
            Mat f = blob.reshape(1,1).clone(); // now our feature has 1000 numbers
   
            // sort into train/test slots:
            if (i<100) {
                // test cat
                test.push_back(f);
            } else
            if (i>=100 && i<700) {
                // train cat
                train.push_back(f);
                labels.at<float>(i-100,0) = 1; // one-hot encoded labels for our ann
            } else
            if (i>=700 && i<800) {
                // test dog
                test.push_back(f);
            } else {
                // train dog
                train.push_back(f);
                labels.at<float>(i-200,1) = 1;
            }
            cout << i << "\r"; // "machine learning should come with a statusbar." ;)
        }
    
        cout << train.size() << " " << labels.size() << " " << test.size() << endl;
        nn->train(train, 0, labels); // yes, that'll take a few minutes ..
        nn->save("cats.dogs.ann.yml.gz");
    
        Mat result;
        // our result array is one-hot encoded, too, which means:
        // if pin 1 is larger than pin 0, -  it predicted a dog, else a cat.
        nn->predict(test,result);
        // cout << result << endl;

        float correct_cat = 0;
        float correct_dog = 0;
        for (int i=0; i<100; i++) // 1st hundred testexamples were cats
            correct_cat += result.at<float>(i,0) > result.at<float>(i,1); // 0, true cat
        for (int i=100; i<200; i++) // 2nd hundred were dogs
            correct_dog += result.at<float>(i,1) > result.at<float>(i,0); // 1, true dog;
        float accuracy = (correct_cat + correct_dog) / 200;
        cout << correct_cat << " " << correct_dog << " : " << accuracy << endl;

        return 0;
    }