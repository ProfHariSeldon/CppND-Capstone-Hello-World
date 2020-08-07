// Created by Thomas H. Lipscomb: https://github.com/ProfHariSeldon/

#ifndef GAME_H
#define GAME_H

// #include <vector>
// Needed to recognize string vectors
// #include <string>
// Needed for Mat
#include <opencv2/core/mat.hpp>

using namespace cv;
using namespace std;

enum ObjectType
{
    noObject,
    objectVehicle,
    objectIntersection,
    objectStreet,
};

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

    void Run(); // method that runs the game 
    string CoinFlip(string sHeads, string sTails); // If heads return "cat" if tails return "dog"
    int RandomImage(int iWidth, int iStart); // Choose a random Cat or Dog image from what I believe is the test set
    string LoadImage(string sCatOrDog, int iImageID); // Show Cat or Dog image and return image filename
    void ClassifyImage(string sCatOrDog, string sImageID); // User presses c to classify image as cat, d to classify image as dog, q to quit
    double CalculateAvgTime(); // Calculate average time it took the user to classify the image
    void CountCorrectAndWrongClassifications(); // Calculate # correct cat, # correct dog, # incorrect cat, # incorrect dog

private:
    bool _bGameRunning; // True if game continues, False to end game
    bool _bGetCorrectKey; // Starts out false, becomes true if c or d is pressed
    Mat _image; // Stores cat or dog image picture
    vector<double> _vdTimeMilli; // List of how long it took to press c or d during the game
    vector<string> _vsCorrectImageID; // List of filenames of correctly classified cats and dogs
    vector<string> _vsWrongImageID; // List of filenames of wrongly classified cats and dogs
    int _iCorrectCat; // Number of correctly classified cats
    int _iCorrectDog; // Number of correctly classified dogs
    int _iWrongCat; // Number of wrongly classified cats
    int _iWrongDog; // Number of wrongly classified dogs
};

#endif