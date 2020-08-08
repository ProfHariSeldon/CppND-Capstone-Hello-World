// Created by Thomas H. Lipscomb: https://github.com/ProfHariSeldon/

#ifndef GAME_H
#define GAME_H

// Below needed for Mat
#include <opencv2/core/mat.hpp>

using namespace cv;
using namespace std;

class Game
{
public:
    // Based on Vehicle.h in https://github.com/ProfHariSeldon/CppND-Program-a-Concurrent-Traffic-Simulation
    // constructor / desctructor
    Game();
    /*
    // Unique destructor not necessary
    ~Game();

    // getters / setters
    void setCurrentStreet(std::shared_ptr<Street> street) { _currStreet = street; };
    void setCurrentDestination(std::shared_ptr<Intersection> destination);

    // typical behaviour methods
    void simulate();

    // miscellaneous
    std::shared_ptr<Vehicle> get_shared_this() { return shared_from_this(); }
    */

    bool _bGameRunning; // Starts out True, game continues while True, game stops when False
    string CoinFlip(string sHeads, string sTails); // If heads return "cat" if tails return "dog"
    int RandomImage(int iWidth, int iStart); // Choose a random Cat or Dog image from (1000-1199)
    string LoadImage(string sHeadsOrTails, int iImageID); // Show Cat or Dog image and return image filename
    void ClassifyImage(string sHeadsOrTails, string sImageID, char cHeadsKey, string sHeads, char cTailsKey, string sTails); // User presses c to classify image as cat, d to classify image as dog, q to quit
    double CalculateAvgTime(); // Calculate average time it took the user to classify the image
    void CountCorrectAndWrongClassifications(string sHeads, string sTails); // Calculate # correct cat, # correct dog, # incorrect cat, # incorrect dog

private:
    Mat _image; // Stores cat or dog image picture
    vector<double> _vdTimeMilli; // List of how long it took to press c or d during the game
    vector<string> _vsCorrectImageID; // List of filenames of correctly classified cats and dogs
    vector<string> _vsWrongImageID; // List of filenames of wrongly classified cats and dogs
    int _iCorrectHeads; // Number of correctly classified cats
    int _iCorrectTails; // Number of correctly classified dogs
    int _iWrongHeads; // Number of wrongly classified cats
    int _iWrongTails; // Number of wrongly classified dogs
};

#endif