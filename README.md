# C++ Capstone Project: I added a manual image classification game to a Convolutional Neural Network image classifier

## OVERVIEW

This is my Capstone independent project for the online course [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).  I chose to do an image classification project because my programming job may involve artificial intelligence such as OpenCV.

I found a Convolutional Neural Network (CNN) SqueezeNet Artificial Intelligence image classifier cats.vs.dogs.cpp, added explanatory comments to the existing code, and added a manual image classification game to it.  I placed the code in this fork of the https://github.com/udacity/CppND-Capstone-Hello-World repo.

Folder CppND-Capstone-Hello-World is the root directory for the files mentioned below:
```$ cd CppND-Capstone-Hello-World```

### What I did

#### C++ programming
* class Game
* constructor Game
* subclass CatsVsDogs
* constructor CatsVsDogs
* public methods in ./src/game.h used in ./src/game.cats.vs.dogs.cpp
* public variable _bGameRunning in game.h shared between ./src/game.cpp and ./src/game.cats.vs.dogs.cpp
* private variables in ./src/game.h
* private variables in ./src/game.cats.vs.dogs.h

#### CMake
* Created ./CMakeLists.txt, the settings file for the Cmake compiler, and added OpenCV 4 to its path to involve OpenCV 4 in the compilation

#### OpenCV 4
* Installed OpenCV 4 from source in Ubuntu 20.04 LTS
* Manually added OpenCV 4 to ldconfig by creating /etc/ld.so.conf.d/opencv.conf
* Used OpenCV 4 to count the milliseconds between the image popping up and the next keystroke
* Used OpenCV 4 to record the keystroke (c for cat, d for dog, q for quit, any other key do nothing)
* Used OpenCV 4 to run Convolutional Neural Network SqueezeNet Artificial Intelligence automatic image classifier (to distinguish cat and dog pictures)

#### Visual Studio Code
* In ./.vscode/settings.json added OpenCV 4 to includePath so that Visual Studio Code can find OpenCV dependencies
* In ./.vscode/launch.json modified to point to executable ./build/classifier

#### GIT
* fork (GitHub) # fork CPPND: Capstone Hello World project
* git rm -r . # delete hello world program from project
* git add . # manually add (basically fork) cats.vs.dogs.cpp and cat-dog images folder to project
* git rn cat-dog images # rename cat-dog images folder to images folder
* git mv # move .cpp files, .h files, squeezenet_v1.1.caffemodel, and squeezenet_v1.1.prototxt to src directory

### Where to find my code:
* Created ./CMakeLists.txt, ./.vscode/launch.json, and ./.vscode/settings.json
* Created ./src/game.cpp, ./src/game.h, ./src/game.cats.vs.dogs.cpp, and ./src/game.cats.vs.dogs.h

### Where to find code I modified:
* Added comments to ./src/cats.vs.dogs.cpp to explain how the code author (berak) used an artificial intelligence to classify cat and dog images
* Added a Run() command to the end of main() in ./src/cats.vs.dogs.cpp to run the manual image classification game

## DETAILS OF PROJECT DEVELOPMENT

This project was forked from the starter repo https://github.com/udacity/CppND-Capstone-Hello-World, however nothing in that starter repo was relevant to creating an image classifier so nothing of the starter repo remains.

These three project code files (./src/cats.vs.dogs.cpp, ./src/squeezenet_v1.1.caffemodel, ./src/squeezenet_v1.1.prototxt) came from this website: https://berak.github.io/smallfry/transfer.html.  I added comments and added a manual image classification game to cats.vs.dogs.cpp.  The dog and cat pictures came from https://github.com/yoggasek/Train_Data.  The other seven project code files I created (./CMakeLists.txt, ./.vscode/launch.json, ./.vscode/settings.json, ./src/game.cpp, ./src/game.h, ./src/game.cats.vs.dogs.cpp, and ./src/game.cats.vs.dogs.h).

There are two blocks of cat and dog pictures.  Those ending in 0-499 and those ending in 1000-1199.  The training set is images ending in 0-99 and the test set is images ending in 100-499 and 1000-1199.  The training set is not large because SqueezeNet was pretrained on millions of images (ImageNet), among them cats & dogs.

### I investigated 4 image classifier GitHub projects before settling on number 5

1. https://github.com/bennyfri/TFMacCpp
  * A Convolutional Neural Network image classifier (that distinguishes dog and cat pictures) using Tensorflow 2.0 and has instructions for how to get it working on a Mac (I am using Ubuntu 20.04 LTS not Mac).  At the time, TensorFlow 2.0 had Python binary install files but not C++ binary install files so TensorFlow 2.0 for C++ had to be built from source.  TensorFlow has to be added to the path in CMakeLists.txt, settings.json, and when building from source in a "nonstandard" directory like /home/tlroot/ ```$ sudo ldconfig``` does not work.  At the time I had not figured out how to get ldconfig working.  After I gave up on this project option I did figure out how to manually add something to ldconfig (I manually added OpenCV 4 to ldconfig in project number 5).  While considering this project I asked questions about how to get TFMacCpp working on two forums:
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

### FYI: How I got this repo's resources

Skip to Build and Run Instructions if https://github.com/ProfHariSeldon/CppND-Capstone-Hello-World.git was cloned (step 1 of Build and Run Instructions below).

* Website that has the resources: https://berak.github.io/smallfry/transfer.html

* ```$ cd /home/tlroot/Documents/C++/Capstone/CppND-Capstone-Hello-World```

* Download this cpp file: https://gist.github.com/berak/70bcf5e8240c4af4426f9eff3f42121c#file-cats-vs-dogs-cpp
* Download: https://raw.githubusercontent.com/DeepScale/SqueezeNet/b5c3f1a23713c8b3fd7b801d229f6b04c64374a5/SqueezeNet_v1.1/squeezenet_v1.1.caffemodel
* Download: https://raw.githubusercontent.com/opencv/opencv_extra/master/testdata/dnn/squeezenet_v1.1.prototxt

* cd OUTSIDE of /home/tlroot/Documents/C++/Capstone/CppND-Capstone-Hello-World
* ```$ git clone https://github.com/yoggasek/Train_Data.git```
* Delete create_csv.py it is not needed.
* Combine cat and dog folders into images folder.  The cats.vs.dogs.cpp Convolutional Neural Network will sort names lexically to separate the dog and cat pictures instead of having them in separate folders.
* Move the images folder into /home/tlroot/Documents/C++/Capstone/CppND-Capstone-Hello-World

* I created my own CMakeLists.txt, settings.json, and launch.json

### Dependencies for Running Locally
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
  * squeezenet_v1.1.prototxt (the structure of the SqueezeNet neural network) is already in this GitHub project src directory or [Download](https://raw.githubusercontent.com/opencv/opencv_extra/master/testdata/dnn/squeezenet_v1.1.prototxt)
  * squeezenet_v1.1.caffemodel (the weights of the layers of the SqueezeNet neural network) is already in this GitHub project src directory or [Download](https://raw.githubusercontent.com/DeepScale/SqueezeNet/b5c3f1a23713c8b3fd7b801d229f6b04c64374a5/SqueezeNet_v1.1/squeezenet_v1.1.caffemodel)

### Installation instructions for OpenCV 4 on Ubuntu 20.04 LTS

OpenCV 4 needs to be installed before cmake works because cats.vs.dogs.cpp and game.cpp use OpenCV 4.

Upgrade to Ubuntu 20.04 LTS:
```
$ sudo do-release-upgrade -d -f DistUpgradeViewGtk3
```

Installation instructions below and some of CMakeLists.txt are based on: https://www.learnopencv.com/install-opencv-4-on-ubuntu-18-04/

Find installOpenCV-4-on-Ubuntu-18-04.sh in the root directory of this GitHub project or download from: https://github.com/spmallick/learnopencv/blob/master/InstallScripts/installOpenCV-4-on-Ubuntu-18-04.sh

For all the following be sure to use your directory (I used my home directory /home/tlroot/)
```
$ cd /home/tlroot/
$ sudo chmod +x ./installOpenCV-4-on-Ubuntu-18-04.sh
$ sudo bash installOpenCV-4-on-Ubuntu-18-04.sh
```

#### Installation Problem:
The following lines failed to add OpenCV 4 to the path [automatically](https://linux.101hacks.com/unix/ldconfig/) (```$ sudo ldconfig``` or ```$ sudo ldconfig -n /home/tlroot/installation/OpenCV-master/lib/```) or [manually](https://linux.101hacks.com/unix/ldconfig/) (insert the below lines manually into /etc/ld.so.conf).
```
include /home/tlroot/installation/OpenCV-master/lib/
include /home/tlroot/installation/OpenCV-master/include/opencv4/
```

Use -v to double-check if ldconfig now has "/home/tlroot/installation/OpenCV-master/lib"
```
$ sudo ldconfig -v
```
https://www.tutorialspoint.com/unix_commands/ldconfig.htm

#### Installation Solution:
The following lines succeeded to add OpenCV 4 to the path, create opencv.conf in /etc/ld.so.conf.d/ and insert:
```
# OpenCV default configuration
/home/tlroot/installation/OpenCV-master/lib/
```
https://answers.opencv.org/question/136182/installation-of-opencv-in-a-local-directory-in-ubuntu-1604/

Use -v to double-check that ldconfig now has "/home/tlroot/installation/OpenCV-master/lib"
```
$ sudo ldconfig -v
```
https://www.tutorialspoint.com/unix_commands/ldconfig.htm

### Build and Run Instructions for this GitHub project

1. git clone https://github.com/ProfHariSeldon/CppND-Capstone-Hello-World.git
2. Check that CMakeLists.txt is in top level GitHub project directory.
3. Check that squeezenet_v1.1.caffemodel and squeezenet_v1.1.prototxt are in ./src directory.
4. Check that launch.json and settings.json are in ./.vscode directory.
5. Check that make, cmake, gcc/g++, and Visual Studio Code are installed.  Install them if not installed.
6. Install Open CV 4 (see above section)
7. Enter build directory: `cd build`
8. Compile: `cmake .. && make`
9. Run it: `./classifier`.
10. Expect the following output:
```
AI DOG CAT IMAGE CLASSIFICATION (SQUEEZENET CNN):
train.size(): [1000 x 1199] labels.size(): [2 x 1199] test.size(): [1000 x 200]

Correct Cat: 100 Correct Dog: 99 : Accuracy: 0.995

USER IMAGE CLASSIFICATION GAME
Instructions:
Type c for cat
Type d for dog
Type q to Quit Game
If you press any other key you must try again
```

Each image that pops up adds the following output:
Image filename, e.g.:
```
../images/cat.1006.jpg
```
Whether you classified the image as a cat or dog
```
Classified as: cat
```
Or:
```
Classified as: dog
```
Time in milliseconds it took for keystroke, e.g.:
```
Time (ms): 1497.6
```
Whether the image was classified correctly:
```
Correct answer
```
Or:
```
Wrong answer
```

When the user presses the q key to quit expect something like the following output:
```
Quit Game
Average time in ms between c or d key presses: 9841.64
Correctly classified cat:2
Correctly classified dog:1
Incorrectly classified cat:1
Incorrectly classified dog:1
Accuracy 0.6
```