//
// Created by ise on 1/1/23.
//

#include "Map.h"
#include "Robot.h"
#include <iostream>

int Robot::robotNum=0;

Robot::Robot(int x, int y, int mapnum){
    row=x;
    col=y;
    robotNum++;
    id=robotNum;
    mapNum=mapnum;
}
Robot::Robot(const Robot& other){
    row=other.row;
    col=other.col;
    id=other.id;
}
Robot::~Robot(){

}
bool Robot::moveRobot(char d){
    if(this->col==-1|| this->row==-1){
        return false;
    }
    if(d=='D'){
        this->col--;
        if(this->col<0){
            this->col=-1;
            this->row=-1;
            return false;
        }
    }
    if(d=='U')
    {
        this->col++;
        if (this->col>6){
            this->col=-1;
            this->row=-1;
            return false;
        }
    }
    if(d=='R'){
        this->row++;
        if(this->row>6){
            this->col=-1;
            this->row=-1;
            return false;
        }

    }
    if(d=='L'){
        this->row--;
        if (this->row<0){
            this->col=-1;
            this->row=-1;
            return false;
        }


    }
    return true;

}
int Robot::getMapNum()const{
    return this->mapNum;
}
int Robot::getRow()const{
    return this->row;
}
int Robot::getCol()const{
    return this->col;
}

int Robot::getRobotId()const{
    return this->id;
}
ostream& operator<<(ostream& out,const Robot& robot ){
    if(robot.col==-1 ||robot.row==-1)
        return  out;
    else{
        if(robot.mapNum>2 || robot.mapNum<1){
            cout<< robot.id <<" GPS: "<< robot.row<<","<< robot.col<<endl;
        }
        else{
            cout<<" "<<robot.id << " Map: "<< robot.mapNum << " GPS: "<< robot.row<<","<< robot.col<<endl;
        }


    }
    return  out;
}

void Robot::down() {
    Robot::robotNum--;
}
