// Created by Thomas H. Lipscomb: https://github.com/ProfHariSeldon/

#ifndef GAME_CATS_VS_DOGS_H
#define GAME_CATS_VS_DOGS_H

#include "game.h"

using namespace std;

class CatsVsDogs : public Game
{
public:
    CatsVsDogs(); // Constructor

    void Run(); // method that runs the game 

private:
    char _cHeadsKey; // Key press to classify image as _sHeads
    string _sHeads; // Images starting with string _sHeads
    char _cTailsKey; // Key press to classify image as _sTails
    string _sTails; // Images starting with string _sTails
};

#endif