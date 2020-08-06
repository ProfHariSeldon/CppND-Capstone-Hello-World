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
    /*
    bool bGameRunning; // True if game continues, False to end game
    vector<double> vdAvgTimeMilli; // list of how long it took to press c or d during the game
    vector<string> vsCorrectImageID; // list of filenames of correctly classified cats and dogs
    vector<string> vsWrongImageID; // list of filenames of wrongly classified cats and dogs
    bool bGetCorrectKey; // starts out false, becomes true if c or d is pressed
    int k; // ASCII Decimal value of identity of key that was pressed
    TickMeter tm; // 
    */
};

#endif