// Created by Thomas H. Lipscomb: https://github.com/ProfHariSeldon/

#include "game.h"
// The Udacity C++ Memory Management Chatbot creates a GUI, however that code is very complicated.
// All I need to do is display dog and cat images and listen for keystrokes so that the user can play a game to see how fast they can classify images.
// I found a tutorial (URL below) to use OpenCV to display images very easily.  The 3 #includes below are required to do this.
// https://docs.opencv.org/2.4/doc/tutorials/introduction/display_image/display_image.html
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
// Below needed for srand and rand
#include <cstdlib>
// Below needed for to_string and .compare
#include <string> 
// Below needed for TickMeter
#include <opencv2/core/utility.hpp>
// Below might be needed to do vector stuff
#include <vector>

using namespace cv;
using namespace std;

Game::Game()
{
    // Constructor
    _bGameRunning = true; // Starts out True, game continues while True, game stops when False
    _iCorrectHeads = 0; // Number of correctly classified cats
    _iCorrectTails = 0; // Number of correctly classified dogs
    _iWrongHeads = 0; // Number of wrongly classified cats
    _iWrongTails = 0; // Number of wrongly classified dogs
}

// Flip a coin to choose to display either sHeads (e.g. "cat") or sTails (e.g. "dog") image
string Game::CoinFlip(string sHeads, string sTails) {
    // This link explains how to initialize the random seed and how to set rand() to the integer range you want.
    // http://www.cplusplus.com/reference/cstdlib/rand/
    // initialize random seed:
    srand (time(NULL));

    // random integer in the range 0 to 1
    int iHeadsOrTails = rand() % 2;
    // "cat" if iHeadsOrTails == 0
    if(iHeadsOrTails == 0) {
        return sHeads;
    }
    // "dog" if iHeadsOrTails == 1
    else if(iHeadsOrTails == 1) {
        return sTails;
    }
    else {
        throw "iHeadsOrTails out of bounds not 0 or 1";
    }
}

// Choose a random Cat or Dog image from what I believe is the test set (1000-1199), return that integer that is after "cat." or "dog." in the filename
int Game::RandomImage(int iWidth, int iStart) {
    // This link explains how to initialize the random seed and how to set rand() to the integer range you want.
    // http://www.cplusplus.com/reference/cstdlib/rand/
    // initialize random seed:
    srand (time(NULL));

    // random integer in the range 1000 to 1199 (the dog or cat test set images I think)
    // v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
    // int iImageID = rand() % 200 + 1000; // random integer in the range 1000 to 1199 (the dog or cat test set images I think)
    int iImageID = rand() % iWidth + iStart;
    if(iImageID < iStart) {
        throw "iImageID out of bounds less than " + to_string(iStart);
    }
    if(iImageID > 1199) {
        throw "iImageID out of bounds greater than " + to_string(iWidth + iStart - 1);
    }
    return iImageID;
}

// Load image with the ID sImageID (e.g. "1001") and return full image filename (e.g. "cat.1001.jpg")
string Game::LoadImage(string sHeadsOrTails, int iImageID) {
        // This link below explains that ${iImageID}.jpg is supposed to work, but I tried it and it does not work for me
        // https://stackoverflow.com/questions/46929684/assigning-a-variable-a-filename-in-bash
        // cout << "../images/cat.${iImageID}.jpg" << endl;
        // cout << "../images/dog.${iImageID}.jpg" << endl;

        // This link below has an alternative I didn't use
        // https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c

        // This link below explains how to display an image using imread, namedWindow, and imshow.
        // https://stackoverflow.com/questions/20168797/opening-and-displaying-an-image-in-c

        // sImageID is Image filename
        string sImageID = sHeadsOrTails + "." + to_string(iImageID) + ".jpg";
        cout << "../images/" + sImageID << endl;
        _image = imread("../images/" + sImageID);

        // create image window named "My Image"
        namedWindow("My Image");
        // show the image on window
        imshow("My Image", _image);

        return sImageID;
}

// User presses c to classify image as cat, d to classify image as dog, q to quit
void Game::ClassifyImage(string sHeadsOrTails, string sImageID, char cHeadsKey, string sHeads, char cTailsKey, string sTails) {
    bool bGetCorrectKey = false; // Starts out false, becomes true if c or d is pressed

    // Keep going until the user types q, c, or d
    while(bGetCorrectKey == false) {
        double dTimeMilli; // How long it took to press a key
        TickMeter tm; // Used to measure the time it took to press a key
        // Start counting time
        tm.start();
        // wait for key input forever because is 0
        // waitKey(0) is the int Decimal (DEC) value of the ASCII key: http://www.asciitable.com/
        char c = (char)waitKey(0); // Convert int aSCII Decimal to char (e.g. convert 113 to 'q')
        if (c == 'q') {  // If key "q" is pressed
            cout << "Quit Game" << endl;
            bGetCorrectKey = true;
            _bGameRunning = false;
            // Stop counting time
            tm.stop();
        }
        else if (c == cHeadsKey) { // If key "c" is pressed
            cout << "Classified as: " + sHeads << endl;
            bGetCorrectKey = true;
            // Stop counting time
            tm.stop();
            // Record time it took to press the key
            dTimeMilli = tm.getTimeMilli();
            cout << "Time (ms): "  << dTimeMilli << endl;
            // Add time it took to press the key to the end of a double vector
            _vdTimeMilli.push_back(dTimeMilli);
            if (sHeadsOrTails == sHeads) { // If the image was a cat
                // Record the image name at the end of the string vector of correct answers
                _vsCorrectImageID.push_back(sImageID);
                cout << "Correct answer" << endl;
            }
            if (sHeadsOrTails == sTails) { // If the image was a dog
                // Record the image name at the end of the string vector of wrong answers
                _vsWrongImageID.push_back(sImageID);
                cout << "Wrong answer" << endl;
            }
        }
        else if (c == cTailsKey) { // If key "d" is pressed
            cout << "Classified as: " + sTails << endl;
            bGetCorrectKey = true;
            // Stop counting time
            tm.stop();
            // Record time it took to press the key
            dTimeMilli = tm.getTimeMilli();
            cout << "Time (ms): "  << dTimeMilli << endl;
            // Add time it took to press the key to the end of a double vector
            _vdTimeMilli.push_back(dTimeMilli);
            if (sHeadsOrTails == sHeads) { // If the image was a cat
                // Record the image name at the end of the string vector of wrong answers
                _vsWrongImageID.push_back(sImageID);
                cout << "Wrong answer" << endl;
            }
            if (sHeadsOrTails == sTails) { // If the image was a dog
                // Record the image name at the end of the string vector of correct answers
                _vsCorrectImageID.push_back(sImageID);
                cout << "Correct answer" << endl;
            }
        }
        else { // If any other key is pressed
            // NOTE: cannot do string + char + string must do string << char << string
            // Type c for cat, d for dog, q to quit
            cout << "Type " << cHeadsKey << " for " + sHeads + ", " << cTailsKey << " for " + sTails + ", q to quit" << endl;
            bGetCorrectKey = false;
        }
    }
}

// Calculate average time it took the user to classify the image
double Game::CalculateAvgTime() {
    double dTotalTimeMilli = 0.0; // Total time system was idle waiting for key presses

    // Using iterator it to iterate through vector
    // http://www.cplusplus.com/reference/vector/vector/begin/
    for (std::vector<double>::iterator it = _vdTimeMilli.begin(); it != _vdTimeMilli.end(); ++it) {
        // Add up total time for all key presses
        dTotalTimeMilli += *it;
    }

    // Find average time
    double dAvgTimeMilli = dTotalTimeMilli / _vdTimeMilli.size(); // Average time it took to press a key
    return dAvgTimeMilli;
}

// Count and print out correctly and incorrectly user-classified pictures
void Game::CountCorrectAndWrongClassifications(string sHeads, string sTails) {
    // WARNING: *it == "cat*" does not work because c++ does not do wildcard characters automatically, so use .compare except can't use an iterator beacuse:
    // WARNING: iterators for the below do not work with .substr or .compare because they are vector strings not strings
    // So for this I prefer "for(auto i: _vsCorrectImageID)".  Can use auto or string.
    // https://www.quora.com/How-do-I-iterate-through-a-vector-using-for-loop-in-C++
    // And use string1.compare(0,3,string2)
    // http://www.cplusplus.com/reference/string/string/compare/
    for(string i: _vsCorrectImageID) {
        if(i.compare(0,sHeads.length(),sHeads) == 0) {
            _iCorrectHeads++; // Count number of correctly classified cats
        }
        if(i.compare(0,sTails.length(),sTails) == 0) {
            _iCorrectTails++; // Count number of correctly classified dogs
        }
    }
    cout << "Correctly classified " + sHeads + ":" << _iCorrectHeads << endl;
    cout << "Correctly classified " + sTails + ":" << _iCorrectTails << endl;

    for(string i: _vsWrongImageID) {
        if(i.compare(0,sHeads.length(),sHeads) == 0) {
            _iWrongHeads++; // Count number of incorrectly classified cats
        }
        if(i.compare(0,sTails.length(),sTails) == 0) {
            _iWrongTails++; // Count number of incorrectly classified dogs
        }
    }
    cout << "Incorrectly classified " + sHeads + ":" << _iWrongHeads << endl;
    cout << "Incorrectly classified " + sTails + ":" << _iWrongTails << endl;
}