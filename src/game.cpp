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
// Below might be needed for converting iRNtestSet to string using to_string and .compare
#include <string> 
// Below might be needed for TickMeter
#include <opencv2/core/utility.hpp>
// Below might be needed to do std::vector
#include <vector>

using namespace cv;
using namespace std;

/*
Game::Game()
{
    // Constructor
    bGetCorrectKey = false;
    bGameRunning = true;
    TickMeter tm;
}
*/

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

    bool bGameRunning = true;

    vector<double> vdAvgTimeMilli; // list of how long it took to press c or d during the game
    vector<string> vsCorrectImageID; // list of filenames of correctly classified cats and dogs
    vector<string> vsWrongImageID; // list of filenames of wrongly classified cats and dogs

    while(bGameRunning) {
        bool bGetCorrectKey = false;
        int k;
        TickMeter tm;
        double dAvgTimeMilli;

        // This link explains how to initialize the random seed and how to set rand() to the integer range you want.
        // http://www.cplusplus.com/reference/cstdlib/rand/
        // initialize random seed:
        srand (time(NULL));

        // random integer in the range 0 to 1
        int iCatOrDog = rand() % 2;

        // random integer in the range 1000 to 1199 (the dog or cat test set images I think)
        int iRNtestSet = rand() % 200 + 1000;         

        // This link below explains that ${iRNtestSet}.jpg is supposed to work, but I tried it and it does not work for me
        // https://stackoverflow.com/questions/46929684/assigning-a-variable-a-filename-in-bash
        // cout << "../cat-dog/cat.${iRNtestSet}.jpg" << endl;
        // cout << "../cat-dog/dog.${iRNtestSet}.jpg" << endl;

        // This link below has an alternative I didn't use
        // https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c

        // Cat or Dog image filename
        string sImageID;

        // This link below explains how to display an image using imread, namedWindow, and imshow.
        // https://stackoverflow.com/questions/20168797/opening-and-displaying-an-image-in-c

        // Define Mat image outside of the below if statement to avoid scope error
        Mat image;

        if (iCatOrDog == 0) { // If the image will be a cat
            sImageID = "cat." + to_string(iRNtestSet) + ".jpg";
            cout << "../cat-dog/" + sImageID << endl;
            // read a cat image
            image = imread("../cat-dog/" + sImageID);
        }
        if (iCatOrDog == 1) { // If the image will be a dog
            sImageID = "dog." + to_string(iRNtestSet) + ".jpg";
            cout << "../cat-dog/" + sImageID << endl;
            // read a dog image
            image = imread("../cat-dog/" + sImageID);
        }

        // create image window named "My Image"
        namedWindow("My Image");
        // show the image on window
        imshow("My Image", image);

        // Keep going until the user types q, c, or d
        while(bGetCorrectKey == false) {
            // Start counting time
            tm.start();
            // wait for key input forever
            // int k is the Decimal (DEC) value of the ASCII key: http://www.asciitable.com/
            k = waitKey(0);
            if (k == 113) {  // If key "q" is pressed
                cout << "Quit Game" << endl;
                bGetCorrectKey = true;
                bGameRunning = false;
                // Stop counting time
                tm.stop();
            }
            else if (k == 99) { // If key "c" is pressed
                cout << "Cat" << endl;
                bGetCorrectKey = true;
                // Stop counting time
                tm.stop();
                // Record time it took to press the key
                dAvgTimeMilli = tm.getAvgTimeMilli();
                cout << "Milli: "  << dAvgTimeMilli << endl;
                // Add time it took to press the key to the end of a double vector
                vdAvgTimeMilli.push_back(dAvgTimeMilli);
                if (iCatOrDog == 0) { // If the image was a cat
                    // Record the image name at the end of the string vector of correct answers
                    vsCorrectImageID.push_back(sImageID);
                    cout << "Correct answer" << endl;
                }
                if (iCatOrDog == 1) { // If the image was a dog
                    // Record the image name at the end of the string vector of wrong answers
                    vsWrongImageID.push_back(sImageID);
                    cout << "Wrong answer" << endl;
                }
            }
            else if (k == 100) { // If key "d" is pressed
                cout << "Dog" << endl;
                bGetCorrectKey = true;
                // Stop counting time
                tm.stop();
                // Record time it took to press the key
                dAvgTimeMilli = tm.getAvgTimeMilli();
                cout << "Milli: "  << dAvgTimeMilli << endl;
                // Add time it took to press the key to the end of a double vector
                vdAvgTimeMilli.push_back(dAvgTimeMilli);
                if (iCatOrDog == 0) { // If the image was a cat
                    // Record the image name at the end of the string vector of wrong answers
                    vsWrongImageID.push_back(sImageID);
                    cout << "Wrong answer" << endl;
                }
                if (iCatOrDog == 1) { // If the image was a dog
                    // Record the image name at the end of the string vector of correct answers
                    vsCorrectImageID.push_back(sImageID);
                    cout << "Correct answer" << endl;
                }
            }
            else { // If any other key is pressed
                cout << "Type c for Cat, d for Dog, q to quit" << endl;
                bGetCorrectKey = false;
            }
        }
    }

    double dTotalTimeMilli = 0.0;
    double dAvgTimeMilli = 0.0;

    // OLD way to do a for loop
    /*
    for(int i = 0; i < vdAvgTimeMilli.size(); i++) {
        dTotalTimeMilli += vdAvgTimeMilli[i];
    }
    */

    // Using iterator it to iterate through vector
    // http://www.cplusplus.com/reference/vector/vector/begin/
    for (std::vector<double>::iterator it = vdAvgTimeMilli.begin(); it != vdAvgTimeMilli.end(); ++it) {
        // Add up total time for all key presses
        dTotalTimeMilli += *it;
    }

    // Find average time
    dAvgTimeMilli = dTotalTimeMilli / vdAvgTimeMilli.size();
    cout << "Average time between c or d key presses: " << dAvgTimeMilli << endl;

    int iCorrectCat = 0;
    int iCorrectDog = 0;

    // WARNING: *it == "cat*" does not work because c++ does not do wildcard characters automatically, so use .compare except can't use an iterator beacuse:
    // WARNING: iterators for the below do not work with .substr or .compare because they are vector strings not strings
    // So for this I prefer "for(auto i: vsCorrectImageID)".  Can use auto or string.
    // https://www.quora.com/How-do-I-iterate-through-a-vector-using-for-loop-in-C++
    // And use string1.compare(0,3,string2)
    // http://www.cplusplus.com/reference/string/string/compare/
    for(string i: vsCorrectImageID) {
        if(i.compare(0,3,"cat") == 0) {
            iCorrectCat++;
        }
        if(i.compare(0,3,"dog") == 0) {
            iCorrectDog++;
        }
    }
    cout << "Correctly classified cats: " << iCorrectCat << endl;
    cout << "Correctly classified dogs: " << iCorrectDog << endl;

    int iWrongCat = 0;
    int iWrongDog = 0;

    for(string i: vsWrongImageID) {
        if(i.compare(0,3,"cat") == 0) {
            iWrongCat++;
        }
        if(i.compare(0,3,"dog") == 0) {
            iWrongDog++;
        }
    }
    cout << "Incorrectly classified cats: " << iWrongCat << endl;
    cout << "Incorrectly classified dogs: " << iWrongDog << endl;
    // TL: MY CODE END OF USER IMAGE CLASSIFICATION GAME
}