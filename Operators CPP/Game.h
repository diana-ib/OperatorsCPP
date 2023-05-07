//
// Created by ise on 1/1/23.
//
#include "Robot.h"
#include "Map.h"
#include <vector>
#ifndef ASSIGNMENT4_GAME_H
#define ASSIGNMENT4_GAME_H

// there are two maps ,perform several operations on it (the game)
//allrobots it's all the robot on two maps
class Game {
    Map map1;
    Map map2;
    vector<Robot*> allRobots;
public:
    //creat game
    Game();
    //deleting the game
    //deleting all robots and maps
    ~Game();
    //the game
    //contains options of the game to play
    //choos a number and play
    void menu();

};


#endif //ASSIGNMENT4_GAME_H
