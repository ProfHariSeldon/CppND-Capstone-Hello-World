// Created by Thomas H. Lipscomb: https://github.com/ProfHariSeldon/

#ifndef GAME_CATS_VS_DOGS_H
#define GAME_CATS_VS_DOGS_H

#include "game.h"

using namespace std;

class CatsVsDogs : public Game
{
public:
    // Based on Vehicle.h in https://github.com/ProfHariSeldon/CppND-Program-a-Concurrent-Traffic-Simulation
    // constructor / desctructor
    CatsVsDogs();
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

private:
    char _cHeadsKey; // Key press to classify image as _sHeads
    string _sHeads; // Images starting with string _sHeads
    char _cTailsKey; // Key press to classify image as _sTails
    string _sTails; // Images starting with string _sTails
};

#endif