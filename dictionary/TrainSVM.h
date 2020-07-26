#include<iostream>
// PATH in settings.json is /home/tlroot/installation/OpenCV-master/include/opencv4/
#include<opencv2/core/core.hpp>
#ifndef TRAINSVM_H_INCLUDED
#define TRAINSVM_H_INCLUDED
using namespace std;
void trainSVM ( );
cv::Mat createTrainImage(vector<string>,vector<string>,const cv::Mat );
void trainSVMFinal(vector<string>,vector<string>,cv::Mat );

#endif // TRAINSVM_H_INCLUDED
