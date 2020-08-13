# C++ Capstone Project: I added a manual image classification game to a Convolutional Neural Network image classifier

## OVERVIEW

This is my Capstone independent project for the online course [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).  I chose to do an image classification project because my programming job may involve artificial intelligence such as OpenCV.

I found a Convolutional Neural Network (CNN) SqueezeNet Artificial Intelligence image classifier cats.vs.dogs.cpp, added explanatory comments to the existing code, and added a manual image classification game to it.  I placed the code in this fork of the https://github.com/udacity/CppND-Capstone-Hello-World repo.

Folder CppND-Capstone-Image-Classifier-Game is the root directory for the files mentioned below:
```
$ cd CppND-Capstone-Image-Classifier-Game
```

### What I did

#### C++ programming
* class Game (game.h line 12)
* constructor Game (game.cpp line 24)
* subclass CatsVsDogs (game.cats.vs.dogs.h line 10)
* constructor CatsVsDogs (game.cats.vs.dogs.cpp line 10)
* public methods in ./src/game.h used in ./src/game.cats.vs.dogs.cpp
* public method 18:Run() in ./src/game.cats.vs.dogs.h used in ./src/cats.vs.dogs.cpp
* public variable 17:bool _bGameRunning in ./src/game.h is shared between ./src/game.cpp and ./src/game.cats.vs.dogs.cpp
* private variables in ./src/game.h
* private variables in ./src/game.cats.vs.dogs.h

#### CMake
* Created ./CMakeLists.txt, the settings file for the Cmake compiler, and added OpenCV 4 to its path to involve OpenCV 4 in the compilation

#### OpenCV 4
* Installed OpenCV 4 from source in Ubuntu 20.04 LTS
* Manually added OpenCV 4 to `ldconfig` by creating /etc/ld.so.conf.d/opencv.conf
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
* rename project from CppND-Capstone-Hello-World to CppND-Capstone-Image-Classifier-Game using GitHub settings

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
  * A Convolutional Neural Network image classifier (that distinguishes dog and cat pictures) using Tensorflow 2.0 and has instructions for how to get it working on a Mac (I am using Ubuntu 20.04 LTS not Mac).  At the time, TensorFlow 2.0 had Python binary install files but not C++ binary install files so TensorFlow 2.0 for C++ had to be built from source.  TensorFlow has to be added to the path in CMakeLists.txt, settings.json, and when building from source in a "nonstandard" directory like /home/tlroot/ `$ sudo ldconfig` does not work.  At the time I had not figured out how to get `ldconfig` working.  After I gave up on this project option I did figure out how to manually add something to `ldconfig` (I manually added OpenCV 4 to `ldconfig` in project number 5).  While considering this project I asked questions about how to get TFMacCpp working on two forums:
  * https://stackoverflow.com/questions/62882248/problem-installing-tensorflow-for-visual-studio-code-c-project-in-ubuntu-18-04
  * https://github.com/tensorflow/tensorflow/issues/41533

2. https://github.com/sjhalayka/opencv_ann_image_cat_dog
  * A Artificial Neural Network image classifier (that distinguishes dog and cat pictures) using OpenCV, however it is not purely C++ it has ann_image.py and get_files.py.

3. https://github.com/huunhan312/convNet
  * A Convolutional Neural Network (using OpenCV) but there is no cnpy.h file in the GitHub project for `#include "cnpy.h"` to find and this code does not classify images out of the box (for example the GitHub page has no images, it is unclear which part of the code is the image classifier, and it is unclear which part of the code returns the results of the image classification).

4. https://github.com/yirgagithub/Cat-and-Dog-SVM-classifier
  * This Support Vector Machine image classifier (that distinguishes dog and cat pictures) was so old that it had 10 lines of deprecated OpenCV code which I asked for advice (link below) on how to fix (I did not have time to take a course on OpenCV) at the link below:
  * https://answers.opencv.org/question/232940/help-updating-10-lines-of-deprecated-opencv-code-in-c/
  * Fortunately a user on that forum pointed me towards an image classifier that was not deprecated: https://berak.github.io/smallfry/transfer.html

5. https://berak.github.io/smallfry/transfer.html
  * The code I settled on it is a C++ Convolutional Neural Network image classifier distingusinging cats and dogs using OpenCV 4.

### FYI: How I got this repo's resources

Skip to Build and Run Instructions if https://github.com/ProfHariSeldon/CppND-Capstone-Image-Classifier-Game.git was cloned (step 1 of Build and Run Instructions below).

* Website that has the resources: https://berak.github.io/smallfry/transfer.html

* ```$ cd /home/tlroot/Documents/C++/Capstone/CppND-Capstone-Image-Classifier-Game```

* Download this cpp file: https://gist.github.com/berak/70bcf5e8240c4af4426f9eff3f42121c#file-cats-vs-dogs-cpp
* Download: https://raw.githubusercontent.com/DeepScale/SqueezeNet/b5c3f1a23713c8b3fd7b801d229f6b04c64374a5/SqueezeNet_v1.1/squeezenet_v1.1.caffemodel
* Download: https://raw.githubusercontent.com/opencv/opencv_extra/master/testdata/dnn/squeezenet_v1.1.prototxt
* Move those 3 files into an src directory

* cd OUTSIDE of /home/tlroot/Documents/C++/Capstone/CppND-Capstone-Image-Classifier-Game
* ```$ git clone https://github.com/yoggasek/Train_Data.git```
* Delete create_csv.py it is not needed.
* Combine cat and dog folders into images folder.  The cats.vs.dogs.cpp Convolutional Neural Network will sort names lexically to separate the dog and cat pictures instead of having them in separate folders.
* Move the images folder into /home/tlroot/Documents/C++/Capstone/CppND-Capstone-Image-Classifier-Game

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
The following lines failed to add OpenCV 4 to the path [automatically](https://linux.101hacks.com/unix/ldconfig/) (`$ sudo ldconfig` or `$ sudo ldconfig -n /home/tlroot/installation/OpenCV-master/lib/`) or [manually](https://linux.101hacks.com/unix/ldconfig/) (insert the below lines manually into /etc/ld.so.conf).
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

1. git clone https://github.com/ProfHariSeldon/CppND-Capstone-Image-Classifier-Game.git
2. Check that CMakeLists.txt is in top level GitHub project directory.
3. Check that squeezenet_v1.1.caffemodel and squeezenet_v1.1.prototxt are in ./src directory.
4. Check that launch.json and settings.json are in ./.vscode directory.
5. Check that make, cmake, gcc/g++, and Visual Studio Code are installed.  Install them if not installed.
6. Install Open CV 4 (see above section)
7. Enter build directory: `cd build`
8. Compile: `cmake .. && make`
9. Run it: `./classifier`
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

## RUBRIC POINTS

### YES: README (All Rubric Points REQUIRED)
* **YES:** The README is included with the project and has instructions for building/running the project.  If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions.  You can submit your writeup as markdown or pdf.
* **YES:** The README describes the project you have built.  The README also indicates the file and class structure, along with the expected behavior or output of the program.
* **YES:** The README indicates which rubric points are addressed. The README also indicates where in the code (i.e. files and line numbers) that the rubric points are addressed.

### YES: Compiling and Testing (All Rubric Points REQUIRED)
* **YES:** The project code must compile and run without errors. 
  * Used `make` and `cmake` with `cmake` settings defined in ./CMakeLists.txt.
  * ./CMakeLists.txt points to Open CV 4 directories 8:`SET(OpenCV_DIR /home/tlroot/installation/OpenCV-master/include/opencv4/)`, 11:`find_package( OpenCV REQUIRED PATHS "/home/tlroot/installation/OpenCV-master/")`, and /home/tlroot/installation/OpenCV-master/lib (20:`target_link_libraries( classifier ${OpenCV_LIBS} )`) so that `cmake` can compile correctly the Open CV 4 files that `#include` points to and the dependencies of those files.
  * opencv.conf created in /etc/ld.so.conf.d/ (see "Installation Solution" section) so that `$ sudo ldconfig` adds Open CV 4 to the path so that compiling works.
  * ./.vscode/launch.json points to executable 11:`"program": "${workspaceFolder}/build/classifier",`
  * ./.vscode/settings.json 64:`"C_Cpp.default.includePath": ["/home/tlroot/installation/OpenCV-master/include/opencv4/"]` so that Visual Studio Code can find `#include` Open CV 4 files.

### YES: Loops, Functions, I/O
* **YES:** A variety of control structures are used in the project.  The project code is clearly organized into functions.
  * Functions I created are declared in ./src/game.h and ./src/game.cats.vs.dogs.h and defined in ./src/game.cpp and ./src/game.cats.vs.dogs.cpp.
* **YES:** The project reads data from an external file or writes data to a file as part of the necessary operation of the program.
  * My 76:Game::LoadImage method (in ./src/game.cpp) uses OpenCV 4's 94:namedWindow method to pop up a window, uses OpenCV 4's 96:imshow method to pop up an image, and uses OpenCV 4's Mat class to select the image to pop up.  The image to pop up is randomized by my 34:Game::CoinFlip and my 56:Game::RandomImage methods (in ./src/game.cpp).
* **YES:** The project accepts input from a user as part of the necessary operation of the program.
  * My 102:Game::ClassifyImage method (in ./src/game.cpp) uses OpenCV 4's 113:waitKey method to wait for and record key presses and OpenCV 4's TickMeter class (108:TickMeter tm;) to measure the number of milliseconds it takes for the user to press "c" to classify the image as a cat or "d" to classify the image as a dog.  Game::ClassifyImage also records whether that classification was correct or not (133:_vsCorrectImageID, 138:_vsWrongImageID, 154:_vsWrongImageID, and 159:_vsCorrectImageID).

### Object Oriented Programming
* **YES:** The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks.  All class data members are explicitly specified as public, protected, or private.
  * ./src/game.cpp contains public methods that are generalized to any manual image1 vs image2 classification game
  * ./src/game.cats.vs.dogs.cpp contains the 18:CatsVsDogs::Run() public method that uses the ./src/game.cpp methods and runs a cat vs dog manual image classification game.
  * ./src/game.h contains public variable 17:bool _bGameRunning is shared between ./src/game.cpp and ./src/game.cats.vs.dogs.cpp
  * ./src/game.h and ./src/game.cats.vs.dogs.h contain public methods and private variables
* **YES:** All class members that are set to argument values are initialized through member initialization lists.
  * All class variables that need to be set to a value that is not null (true, 0, 'c', "cat", 'd', or "dog") are declared in the ./src/game.h or ./src/game.cats.vs.dogs.h and defined in the 24:Game::Game() constructor in ./src/game.cpp or the 10:CatsVsDogs::CatsVsDogs() constructor in ./src/game.cats.vs.dogs.cpp
* **YES:** All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.
  * All class member functions have clear function names and comments.
* **YES:** Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions.
  * Class CatsVsDogs (./src/game.cats.vs.dogs.h line 10) is a subclass of Game (./src/game.h line 12)
  * private variables in class Game (./src/game.cpp and ./src/game.h) are hidden from (not inherited by) class CatsVsDogs (./src/game.cats.vs.dogs.cpp and ./src/game.cats.vs.dogs.h).
  * ./src/game.cats.vs.dogs.cpp uses the functions (they are all public) defined in ./src/game.cpp and public variable 17:bool _bGameRunning in ./src/game.h is shared between ./src/game.cpp and ./src/game.cats.vs.dogs.cpp
* **PARTIAL:** Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified.
  * Inheritance hierarchies for class Game (./src/game.cpp and ./src/game.h) and class CatsVsDogs (./src/game.cats.vs.dogs.cpp and ./src/game.cats.vs.dogs.h) are logical.  Code is not complicated enough to require composition, abstract classes, virtual functions, or override functions.
* **NO:** One function is overloaded with different signatures for the same function name.
  * Code is not complicated enough to require this.
* **NO:** One member function in an inherited class overrides a virtual base class member function.
  * Code is not complicated enough to require this.
* **NO:** One function is declared with a template that allows it to accept a generic parameter.
  * Code is not complicated enough to require this.

### Memory Management
* **NO:** At least two variables are defined as references, or two functions use pass-by-reference in the project code.
  * Code is not complicated enough to require this.
* **NO:** At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor.
  * Code is not complicated enough to require this.
* **PARTIAL (BY DEFAULT):** The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction.
  * My code is not complicated enough to require RAII but my variables are set up so when they go out of scope they are destroyed or garbage collected by default.
* **NO:** For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor are defined, then all of these functions are defined.
  * Code is not complicated enough to require Rule of Five.
* **NO:** For classes with move constructors, the project returns objects of that class by value, and relies on the move constructor, instead of copying the object.
  * Code is not complicated enough to require Rule of Five.
* **NO:** The project uses at least one smart pointer: unique_ptr, shared_ptr, or weak_ptr. The project does not use raw pointers.
  * Code is not complicated enough to require this.

### NO: Concurrency
* **NO:** The project uses multiple threads in the execution.
  * Code is not multi-thread.
* **NO:** A promise and future is used to pass data from a worker thread to a parent thread in the project code.
  * Code is not multi-thread.
* **NO:** A mutex or lock (e.g. std::lock_guard or `std::unique_lock) is used to protect data that is shared across multiple threads in the project code.
  * Code is not multi-thread.
* **NO:** A std::condition_variable is used in the project code to synchronize thread execution.
  * Code is not multi-thread.