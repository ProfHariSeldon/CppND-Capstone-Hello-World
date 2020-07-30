# see CMake Lists.txt file in /home/tlroot/Documents/C++/OOP/Project/CppND-System-Monitor
# https://www.learnopencv.com/install-opencv-4-on-ubuntu-18-04/
cmake_minimum_required(VERSION 3.1)
# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

SET(OpenCV_DIR /home/tlroot/installation/OpenCV-master/include/opencv4/)

# https://stackoverflow.com/questions/53528125/fatal-error-no-such-file-or-directory-when-im-sure-i-have-set-find-package-cor
find_package( OpenCV REQUIRED PATHS "/home/tlroot/installation/OpenCV-master/")

project(classifier)

file(GLOB SOURCES "/*.cpp")
# add_executable(classifier ${SOURCES})
add_executable( classifier cats.vs.dogs.cpp )

# https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_gcc_cmake/linux_gcc_cmake.html
target_link_libraries( classifier ${OpenCV_LIBS} )
# target_link_libraries( classifier "/home/tlroot/installation/OpenCV-master/lib/" )

# add_executable( DisplayImage DisplayImage.cpp )
