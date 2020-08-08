# CPPND: Capstone Hello World Repo Fork modified to import a Convolutional Neural Network image classifier distinguishing cats and dogs, to which I added a manual image classification game

OVERVIEW
--------

This is my Capstone project for online course [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).  The purpose of the Capstone project is for the student to undertake an independent project.

For my Capstone project I ............. found, extended it, results into a game.  because my programming job may involve artificial intelligence such as OpenCV.

I created a manual image classification game by extending the cats.vs.dogs project ..... yadditions to cats.vs.dogs.cpp


Technologies I used or programmed

C++
class
subclass
methods
constructor

CMake
CMakeLists.txt, 

OpenCV
Installed OpenCV in Ubuntu 20.04 LTS
The Capstone Project gave me a chance to learn how to build a package (OpenCV) from source, add that package to thae ldconfig path manually (because doing so automatically failed), set up a CMakeLists.txt file to get cmake to utilize OpenCV, and set up settings.json and launch.json files to get Visual Studio Code #include to find OpenCV and run the .cpp file. 
count
keystokes

VS
settings.json
launch.json,

GIT
fork (GitHub)
git add .
rn
mv
rm


Where to find my code:
* I created ./CMakeLists.txt, ./.json/launch.json, and settings.json
* reating game.cpp, game.h. game.cats.vs.dogs.cpp, and game.cats.vs.dogs.h
* I added comments to cats.vs.dogs.cpp to explain how the code author (berak) used an artificial intelligence to classify cat and dog imagesa
* I added a Run() command to the end of main() in cats.vs.dogs.cpp to run the manual image classification game



DETAILS OF PROJECT DEVELOPMENT
------------------------------

There are two blocks of cat and dog pictures.  Those ending in 0-499 and those ending in 1000-1199.  At the moment I am not sure which become the training set and which become the test set.

This project was forked from a starter repo for the Capstone project in the , however nothing in that starter repo was relevant to creating an image classifier so nothing of the starter repo remains.

The project files came from this website and were then modified by me: https://berak.github.io/smallfry/transfer.html (cats.vs.dogs.cpp, caffemodel, prototxt, and dog and cat pictures).


## I investigated 4 image classifier GitHub projects before settling on #5

1. https://github.com/bennyfri/TFMacCpp
  * A Convolutional Neural Network image classifier (that distinguishes dog and cat pictures) using Tensorflow 2.0 and has instructions for how to get it working on a Mac (I am using Ubuntu 20.04 LTS not Mac).  At the time, TensorFlow 2.0 had Python binary install files but not C++ binary install files so TensorFlow 2.0 for C++ had to be built from source.  TensorFlow has to be added to the path in CMakeLists.txt, settings.json, and when building from source in a "nonstandard" directory like /home/tlroot/ ```$ sudo ldconfig``` does not work.  At the time I had not figured out how to get ldconfig working.  Later I did but by then I was using https://berak.github.io/smallfry/transfer.html not TFMacCpp.  I asked questions about how to get TFMacCpp working on two forums:
  * https://stackoverflow.com/questions/62882248/problem-installing-tensorflow-for-visual-studio-code-c-project-in-ubuntu-18-04
  * https://github.com/tensorflow/tensorflow/issues/41533

2. https://github.com/sjhalayka/opencv_ann_image_cat_dog
  * A Artificial Neural Network image classifier (that distinguishes dog and cat pictures) using OpenCV, however it is not purely C++ it has ann_image.py and get_files.py.

3. https://github.com/huunhan312/convNet
  * A Convolutional Neural Network (using OpenCV) but there is no cnpy.h file in the GitHub project for ```#include "cnpy.h"``` to find and this code does not classify images out of the box (for example the GitHub page has no images, it is unclear which part of the code is the image classifier, and it is unclear which part of the code returns the results of the image classification).

4. https://github.com/yirgagithub/Cat-and-Dog-SVM-classifier
  * This Support Vector Machine image classifier (that distinguishes dog and cat pictures) was so old that it had 10 lines of deprecated OpenCV code which I asked for advice (link below) on how to fix (I did not have time to take a course on OpenCV) at the link below:
  * https://answers.opencv.org/question/232940/help-updating-10-lines-of-deprecated-opencv-code-in-c/
  * Fortunately a user on that forum pointed me towards an image classifier that was not deprecated: https://berak.github.io/smallfry/transfer.html

5. https://berak.github.io/smallfry/transfer.html
  * The code I settled on it is a C++ Convolutional Neural Network image classifier distingusinging cats and dogs using OpenCV 4.

## Dependencies for Running Locally
* cmake >= 3.16.3
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.2.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 9.3.0
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* OpenCV >= 4.4.0
  * Linux: [Install OpenCV 4.0 on Ubuntu 18.04](https://www.learnopencv.com/install-opencv-4-on-ubuntu-18-04/) - [Code](https://github.com/spmallick/learnopencv/blob/master/InstallScripts/installOpenCV-4-on-Ubuntu-18-04.sh)
  * Mac: [Install OpenCV 4.0 on Mac](https://www.learnopencv.com/install-opencv-4-on-macos/) - [Code](https://github.com/spmallick/learnopencv/blob/master/InstallScripts/installOpenCV-4-macos.sh)
  * Windows: [Install OpenCV 4.0 on Windows](https://www.learnopencv.com/install-opencv-4-on-windows/) - [Code](https://github.com/spmallick/learnopencv/tree/master/InstallScripts/Windows-4)
* squeezenet v1.1
  * squeezenet_v1.1.caffemodel is already in this GitHub project src directory or [Download](https://raw.githubusercontent.com/DeepScale/SqueezeNet/b5c3f1a23713c8b3fd7b801d229f6b04c64374a5/SqueezeNet_v1.1/squeezenet_v1.1.caffemodel)
  * squeezenet_v1.1.prototxt is already in this GitHub project src directory or [Download](https://raw.githubusercontent.com/opencv/opencv_extra/master/testdata/dnn/squeezenet_v1.1.prototxt)

## Installation instructions for OpenCV 4 on Ubuntu 20.04 LTS

OpenCV 4 needs to be installed before cmake works because this project's .cpp file uses OpenCV 4.

Upgrade to Ubuntu 20.04 LTS:
```
$ sudo do-release-upgrade -d -f DistUpgradeViewGtk3
```

These installation instructions below and some of CMakeLists.txt are based on: https://www.learnopencv.com/install-opencv-4-on-ubuntu-18-04/

Find installOpenCV-4-on-Ubuntu-18-04.sh in the root directory of this GitHub project or download from: https://github.com/spmallick/learnopencv/blob/master/InstallScripts/installOpenCV-4-on-Ubuntu-18-04.sh

building from Source in my home directory /home/tlroot/ (for all following code be sure to use your directory)
```
$ cd /home/tlroot/
$ sudo chmod +x ./installOpenCV-4-on-Ubuntu-18-04.sh
$ sudo bash installOpenCV-4-on-Ubuntu-18-04.sh
```

PROBLEM: adding OpenCV 4 to the path is harder than usual (possibly because I compiled it in /home/tlroot/ which might be nonstandard).
Usually (but not this time) do it this automatic way:
```
$ sudo ldconfig
```
Or this manual way:
```
$ sudo -n /home/tlroot/installation/OpenCV-master/lib/
```
https://linux.101hacks.com/unix/ldconfig/
Or insert this manually:
include /home/tlroot/installation/OpenCV-master/lib/
into /etc/ld.so.conf
```
$ sudo ldconfig
```
https://www.tutorialspoint.com/unix_commands/ldconfig.htm
HOWEVER neither worked for me.

SOLUTION from https://answers.opencv.org/question/136182/installation-of-opencv-in-a-local-directory-in-ubuntu-1604/:
Create opencv.conf in /etc/ld.so.conf.d/ and insert:
```
# OpenCV default configuration
/home/tlroot/installation/OpenCV-master/lib/
# https://answers.opencv.org/question/136182/installation-of-opencv-in-a-local-directory-in-ubuntu-1604/
```

Use -v to double-check that ldconfig now has "/home/tlroot/installation/OpenCV-master/lib:"
```
$ sudo ldconfig -v
```

## Basic Build Instructions

1. git clone https://github.com/ProfHariSeldon/CppND-Capstone-Hello-World.git
2. Check that CMakeLists.txt is in top level GitHub project directory.
3. Check that squeezenet_v1.1.caffemodel and squeezenet_v1.1.prototxt are in src directory.
4. Check that launch.json and settings.json are in ./.vscode directory.
5. Check that make, cmake, gcc/g++, and Visual Studio Code are installed.  Install them if not installed.
6. Install Open CV 4 (see above section)
7. Make a build directory in the top level directory: `mkdir build && cd build`
8. Compile: `cmake .. && make`
9. Run it: `./classifier`.

## How I got this repo's resources

If https://github.com/ProfHariSeldon/CppND-Capstone-Hello-World.git was cloned (step 1 of Basic Build Instructions) do not do the below:

Website that has the resources
https://berak.github.io/smallfry/transfer.html

```
$ cd /home/tlroot/Documents/C++/Capstone/CppND-Capstone-Hello-World
```
Download this cpp file: https://gist.github.com/berak/70bcf5e8240c4af4426f9eff3f42121c#file-cats-vs-dogs-cpp

Download: https://raw.githubusercontent.com/DeepScale/SqueezeNet/b5c3f1a23713c8b3fd7b801d229f6b04c64374a5/SqueezeNet_v1.1/squeezenet_v1.1.caffemodel

Download: https://raw.githubusercontent.com/opencv/opencv_extra/master/testdata/dnn/squeezenet_v1.1.prototxt

cd OUTSIDE of /home/tlroot/Documents/C++/Capstone/CppND-Capstone-Hello-World
Git clone https://github.com/yoggasek/Train_Data.git
Delete create_csv.py it is not needed.
Combine cat and dog folders into images folder.  The cpp Convolutional Neural Network will sort names lexically to separate the dog and cat pictures instead of having them in separate folders.
Move the images folder into /home/tlroot/Documents/C++/Capstone/CppND-Capstone-Hello-World

I created my own CMakeLists.txt, settings.json, and launch.json