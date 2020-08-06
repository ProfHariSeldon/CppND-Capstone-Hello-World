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
    /*
    // constructor / desctructor
    Game();
    ~Game();

    // getter and setter
    int getID() { return _id; }
    void setPosition(double x, double y);
    void getPosition(double &x, double &y);
    ObjectType getType() { return _type; }

    // typical behaviour methods
    virtual void simulate(){};
    */

    void Run();

private:
    bool bGameRunning; // True if game continues, False to end game
    TickMeter tm; // Used to measure the time it took to press a key
    double dTimeMilli; // how long it took to press a key
    vector<double> vdTimeMilli; // list of how long it took to press c or d during the game
    string sImageID; // Cat or Dog image filename
    vector<string> vsCorrectImageID; // list of filenames of correctly classified cats and dogs
    vector<string> vsWrongImageID; // list of filenames of wrongly classified cats and dogs
    bool bGetCorrectKey; // starts out false, becomes true if c or d is pressed
    int k; // ASCII Decimal value, the identity of the key that was pressed
    int iCatOrDog; // Binary coin flip to decide whether to dispaly a cat (0) or dog (1)
    int iRNtestSet; // Random number in the range 1000 to 1199 (the dog or cat test set images I think)
    Mat image; // stores cat or dog image picture
    double dTotalTimeMilli; // total time system was idle waiting for key presses
    double dAvgTimeMilli; // average time it took to press a key
};

#endif