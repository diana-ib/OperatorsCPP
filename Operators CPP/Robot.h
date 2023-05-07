//
// Created by ise on 1/1/23.
//

#ifndef ASSIGNMENT4_ROBOT_H
#define ASSIGNMENT4_ROBOT_H
#include <iostream>
using namespace std;
//this class is to creat object robot, the robot has id, col, row and map number
//the id is static , in this file we just defined it
//
class Robot {
    static int robotNum;
    int  row;
    int col;
    int mapNum;
    int id;
public:
    //default constructor :creation robot inputs the coordinates the robot in the map and num of which map
    Robot(int x, int y, int mapnum);
    //copy constructor
    Robot(const Robot& other);
    //deleting a robot
    ~Robot();
    //input : char (U,D,L,R) which direction to move the robot
    //return true if after moving it stays within the boundaries of the map else return false
    bool moveRobot(char d);
    //returning number of which map the robot is on
    //this is const because you don't change the map number only returning it
    int getMapNum()const;
    //returning number of the row ,that robot is on
    //this is const because you don't change the row number only returning it
    int getRow()const;
    //returning number of the column ,that robot is on
    //this is const because you don't change the column number only returning it
    int getCol()const;
    //returning ID number of the robot
    //this is const because you don't change the ID robot number only returning it
    int getRobotId()const;
    //print the robot
    //this is const because you don't change only printing
    friend ostream& operator<<(ostream& out,const Robot& robot );
    static void down();
};


#endif //ASSIGNMENT4_ROBOT_H
