//
// Created by ise on 1/1/23.
//

#ifndef ASSIGNMENT4_MAP_H
#define ASSIGNMENT4_MAP_H
#include "Robot.h"
#include <iostream>
#include <vector>
#define numRows 7
#define numCol 7
using namespace std;
//each map is divided into cells , 0-transition, 1-wall
//if the cell is zero -it's mean maybe there is a robot or more
//robot is name of the robots  vector in the same cell
class Map {
    vector<Robot*> robot;
    int size;
    int mapNum;
    int map[numCol][numRows];
public:
    //create a map
    Map();
    //create a map
    Map(int m[numCol][numRows], int num);
    //deleting a map
    // deleting all the robots in the map
    ~Map();
    //adding new robot to the map returning true if succeeded else false
    bool addRobot(Robot* r);
    //deleteng robot from the map returning true if succeeded else false
    bool deleteRobot(int robotnum);
    //create new map , this + other , because the maps are not changed (this , map2 (other)) the both is const
    Map operator+(const Map& map2)const;
    //change this map , add map2 with unchanged (const) to this map , returning this map
    void operator+=(const Map& map2);
    //copying map2 to this map with unchanged (const) to map2, returning this map
    Map& operator=(const Map& map2);
    //check if this map and map2 is similar without changing the maps
    bool operator==(const Map& map2)const;
    //to printing the map , we trusted the ostream department to be my friend
    friend ostream& operator<<(ostream& out,const Map& map2 );



};


#endif //ASSIGNMENT4_MAP_H
