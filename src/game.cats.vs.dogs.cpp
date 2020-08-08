// Created by Thomas H. Lipscomb: https://github.com/ProfHariSeldon/

#include "game.cats.vs.dogs.h"

#include <iostream>

using namespace std;

CatsVsDogs::CatsVsDogs() {
}

// Stay playing game in while loop until quit game
void CatsVsDogs::Run() {
    char cHeadsKey = 'c';
    string sHeads = "cat";
    char cTailsKey = 'd';
    string sTails = "dog";

    cout << "USER IMAGE CLASSIFICATION GAME" << endl;
    cout << "Instructions:" << endl;
    cout << "Type " << cHeadsKey << " for " + sHeads << endl; // Type c for cat
    cout << "Type " << cTailsKey << " for " + sTails << endl; // Type d for dog
    cout << "Type q to Quit Game" << endl;
    cout << "If you press any other key you must try again" << endl;
    cout << endl;

    while(_bGameRunning) { // While game is running

        // Flip a coin to choose to display either "cat" or "dog" image
        string sHeadsOrTails = Game::CoinFlip(sHeads, sTails);

        // I believe the CNN test set is (0-99) and the CNN training set is (100-499, 1000-1199)
        // Iterating through both 100-499 and 1000-1199 is hard just 1000-1199 is easier
        // Choose a random Cat or Dog image from (1000-1199), return that integer that is after "cat." or "dog." in the filename
        int iImageID = Game::RandomImage(200, 1000);

        // Load image with the ID sImageID (e.g. "1001") and return full image filename (e.g. "cat.1001.jpg")
        string sImageID = Game::LoadImage(sHeadsOrTails, iImageID);

        // User presses c to classify image as cat, d to classify image as dog, q to quit
        Game::ClassifyImage(sHeadsOrTails, sImageID, cHeadsKey, sHeads, cTailsKey, sTails);
    }

    // Game is over calculate score

    // Calculate average time it took the user to classify the image
    double dAvgTimeMilli = Game::CalculateAvgTime();

    cout << "Average time in ms between c or d key presses: " << dAvgTimeMilli << endl;

    // Count and print out number of correctly and incorrectly user-classified pictures
    Game::CountCorrectAndWrongClassifications(sHeads, sTails);
}