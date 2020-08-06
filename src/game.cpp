// Created by Thomas H. Lipscomb: https://github.com/ProfHariSeldon/

#include "game.h"
// The Udacity C++ Memory Management Chatbot creates a GUI, however that code is very complicated.
// All I need to do is display dog and cat images and listen for keystrokes so that the user can play a game to see how fast they can classify images.
// I found a tutorial (URL below) to use OpenCV to display images very easily.  The 3 #includes below are required to do this.
// https://docs.opencv.org/2.4/doc/tutorials/introduction/display_image/display_image.html
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
// Below might be needed for srand and rand
#include <cstdlib>
// Below might be needed for converting _iRNtestSet to string using to_string and .compare
#include <string> 
// Below might be needed for TickMeter
#include <opencv2/core/utility.hpp>
// Below might be needed to do std::vector
#include <vector>

using namespace cv;
using namespace std;

Game::Game()
{
    // Constructor
    _bGameRunning = true; // True if game continues, False to end game
    _bGetCorrectKey = false; // Starts out false, becomes true if c or d is pressed
    _dTotalTimeMilli = 0.0; // Total time system was idle waiting for key presses
    _dAvgTimeMilli = 0.0; // Average time it took to press a key
    _iCorrectCat = 0; // Number of correctly classified cats
    _iCorrectDog = 0; // Number of correctly classified dogs
    _iWrongCat = 0; // Number of wrongly classified cats
    _iWrongDog = 0; // Number of wrongly classified dogs
}

    // TL: MY CODE START OF USER IMAGE CLASSIFICATION GAME
        // Stay playing game in while loop until quit game
void Game::Run() {
    cout << "USER IMAGE CLASSIFICATION GAME" << endl;
    cout << "Instructions:" << endl;
    cout << "Type c for Cat" << endl;
    cout << "Type d for Dog" << endl;
    cout << "Type q to Quit Game" << endl;
    cout << "If you press any other key you must try again" << endl;
    cout << endl;

    // bool _bGameRunning = true;

    // vector<double> _vdTimeMilli; // list of how long it took to press c or d during the game
    // vector<string> _vsCorrectImageID; // list of filenames of correctly classified cats and dogs
    // vector<string> _vsWrongImageID; // list of filenames of wrongly classified cats and dogs

    while(_bGameRunning) {
        _bGetCorrectKey = false;
        // int _k;
        // TickMeter _tm;
        // double _dTimeMilli;

        // This link explains how to initialize the random seed and how to set rand() to the integer range you want.
        // http://www.cplusplus.com/reference/cstdlib/rand/
        // initialize random seed:
        srand (time(NULL));

        // random integer in the range 0 to 1
        _iCatOrDog = rand() % 2;

        // random integer in the range 1000 to 1199 (the dog or cat test set images I think)
        _iRNtestSet = rand() % 200 + 1000;         

        // This link below explains that ${_iRNtestSet}.jpg is supposed to work, but I tried it and it does not work for me
        // https://stackoverflow.com/questions/46929684/assigning-a-variable-a-filename-in-bash
        // cout << "../cat-dog/cat.${_iRNtestSet}.jpg" << endl;
        // cout << "../cat-dog/dog.${_iRNtestSet}.jpg" << endl;

        // This link below has an alternative I didn't use
        // https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c

        // Cat or Dog image filename
        // string _sImageID;

        // This link below explains how to display an image using imread, namedWindow, and imshow.
        // https://stackoverflow.com/questions/20168797/opening-and-displaying-an-image-in-c

        // Define Mat image outside of the below if statement to avoid scope error
        // Mat _image;

        if (_iCatOrDog == 0) { // If the image will be a cat
            _sImageID = "cat." + to_string(_iRNtestSet) + ".jpg";
            cout << "../cat-dog/" + _sImageID << endl;
            // read a cat image
            _image = imread("../cat-dog/" + _sImageID);
        }
        if (_iCatOrDog == 1) { // If the image will be a dog
            _sImageID = "dog." + to_string(_iRNtestSet) + ".jpg";
            cout << "../cat-dog/" + _sImageID << endl;
            // read a dog image
            _image = imread("../cat-dog/" + _sImageID);
        }

        // create image window named "My Image"
        namedWindow("My Image");
        // show the image on window
        imshow("My Image", _image);

        // Keep going until the user types q, c, or d
        while(_bGetCorrectKey == false) {
            // Start counting time
            _tm.start();
            // wait for key input forever
            // int k is the Decimal (DEC) value of the ASCII key: http://www.asciitable.com/
            _k = waitKey(0);
            if (_k == 113) {  // If key "q" is pressed
                cout << "Quit Game" << endl;
                _bGetCorrectKey = true;
                _bGameRunning = false;
                // Stop counting time
                _tm.stop();
            }
            else if (_k == 99) { // If key "c" is pressed
                cout << "Cat" << endl;
                _bGetCorrectKey = true;
                // Stop counting time
                _tm.stop();
                // Record time it took to press the key
                _dTimeMilli = _tm.getTimeMilli();
                cout << "Milli: "  << _dTimeMilli << endl;
                // Add time it took to press the key to the end of a double vector
                _vdTimeMilli.push_back(_dTimeMilli);
                if (_iCatOrDog == 0) { // If the image was a cat
                    // Record the image name at the end of the string vector of correct answers
                    _vsCorrectImageID.push_back(_sImageID);
                    cout << "Correct answer" << endl;
                }
                if (_iCatOrDog == 1) { // If the image was a dog
                    // Record the image name at the end of the string vector of wrong answers
                    _vsWrongImageID.push_back(_sImageID);
                    cout << "Wrong answer" << endl;
                }
            }
            else if (_k == 100) { // If key "d" is pressed
                cout << "Dog" << endl;
                _bGetCorrectKey = true;
                // Stop counting time
                _tm.stop();
                // Record time it took to press the key
                _dTimeMilli = _tm.getTimeMilli();
                cout << "Milli: "  << _dTimeMilli << endl;
                // Add time it took to press the key to the end of a double vector
                _vdTimeMilli.push_back(_dTimeMilli);
                if (_iCatOrDog == 0) { // If the image was a cat
                    // Record the image name at the end of the string vector of wrong answers
                    _vsWrongImageID.push_back(_sImageID);
                    cout << "Wrong answer" << endl;
                }
                if (_iCatOrDog == 1) { // If the image was a dog
                    // Record the image name at the end of the string vector of correct answers
                    _vsCorrectImageID.push_back(_sImageID);
                    cout << "Correct answer" << endl;
                }
            }
            else { // If any other key is pressed
                cout << "Type c for Cat, d for Dog, q to quit" << endl;
                _bGetCorrectKey = false;
            }
        }
    }

    // double _dTotalTimeMilli = 0.0;
    // double _dAvgTimeMilli = 0.0;

    // OLD way to do a for loop
    /*
    for(int i = 0; i < _vdTimeMilli.size(); i++) {
        _dTotalTimeMilli += _vdTimeMilli[i];
    }
    */

    // Using iterator it to iterate through vector
    // http://www.cplusplus.com/reference/vector/vector/begin/
    for (std::vector<double>::iterator it = _vdTimeMilli.begin(); it != _vdTimeMilli.end(); ++it) {
        // Add up total time for all key presses
        _dTotalTimeMilli += *it;
    }

    // Find average time
    _dAvgTimeMilli = _dTotalTimeMilli / _vdTimeMilli.size();
    cout << "Average time between c or d key presses: " << _dAvgTimeMilli << endl;

    // int _iCorrectCat = 0;
    // int _iCorrectDog = 0;

    // WARNING: *it == "cat*" does not work because c++ does not do wildcard characters automatically, so use .compare except can't use an iterator beacuse:
    // WARNING: iterators for the below do not work with .substr or .compare because they are vector strings not strings
    // So for this I prefer "for(auto i: _vsCorrectImageID)".  Can use auto or string.
    // https://www.quora.com/How-do-I-iterate-through-a-vector-using-for-loop-in-C++
    // And use string1.compare(0,3,string2)
    // http://www.cplusplus.com/reference/string/string/compare/
    for(string i: _vsCorrectImageID) {
        if(i.compare(0,3,"cat") == 0) {
            _iCorrectCat++;
        }
        if(i.compare(0,3,"dog") == 0) {
            _iCorrectDog++;
        }
    }
    cout << "Correctly classified cats: " << _iCorrectCat << endl;
    cout << "Correctly classified dogs: " << _iCorrectDog << endl;

    // int _iWrongCat = 0;
    // int _iWrongDog = 0;

    for(string i: _vsWrongImageID) {
        if(i.compare(0,3,"cat") == 0) {
            _iWrongCat++;
        }
        if(i.compare(0,3,"dog") == 0) {
            _iWrongDog++;
        }
    }
    cout << "Incorrectly classified cats: " << _iWrongCat << endl;
    cout << "Incorrectly classified dogs: " << _iWrongDog << endl;
    // TL: MY CODE END OF USER IMAGE CLASSIFICATION GAME
}