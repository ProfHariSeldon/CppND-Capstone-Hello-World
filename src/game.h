#ifndef GAME_H
#define GAME_H

// #include <vector>
// Needed to recognize string vectors
// #include <string>
// Needed for TickMeter
#include <opencv2/core/utility.hpp>

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
    // constructor / desctructor
    Game();
    /*
    ~Game();

    // getter and setter
    int getID() { return _id; }
    void setPosition(double x, double y);
    void getPosition(double &x, double &y);
    ObjectType getType() { return _type; }

    // typical behaviour methods
    virtual void simulate(){};
    */

    // method that runs the game 
    void Run();

private:
    bool _bGameRunning; // True if game continues, False to end game
    TickMeter _tm; // Used to measure the time it took to press a key
    double _dTimeMilli; // How long it took to press a key
    vector<double> _vdTimeMilli; // List of how long it took to press c or d during the game
    string _sImageID; // Cat or Dog image filename
    vector<string> _vsCorrectImageID; // List of filenames of correctly classified cats and dogs
    vector<string> _vsWrongImageID; // List of filenames of wrongly classified cats and dogs
    bool _bGetCorrectKey; // Starts out false, becomes true if c or d is pressed
    int _k; // ASCII Decimal value, the identity of the key that was pressed
    int _iCatOrDog; // Binary coin flip to decide whether to dispaly a cat (0) or dog (1)
    int _iRNtestSet; // Random number in the range 1000 to 1199 (the dog or cat test set images I think)
    Mat _image; // Stores cat or dog image picture
    double _dTotalTimeMilli; // Total time system was idle waiting for key presses
    double _dAvgTimeMilli; // Average time it took to press a key
    int _iCorrectCat; // Number of correctly classified cats
    int _iCorrectDog; // Number of correctly classified dogs
    int _iWrongCat; // Number of wrongly classified cats
    int _iWrongDog; // Number of wrongly classified dogs
};

#endif