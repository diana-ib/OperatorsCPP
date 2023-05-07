//
// Created by ise on 1/1/23.
//
#include "Robot.h"
#include "Map.h"
#include <iostream>
using namespace std;
Map::Map(){
    this->size=0;
    this->mapNum=0;

}
Map::Map(int m[7][7], int num){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            map[i][j]=m[i][j];
        }
    }
    this->size=0;
    this->mapNum=num;
}
Map::~Map(){
    for(int i=0;i<size;i++){
        if(robot[i])
            delete robot[i];
    }
}
bool Map::addRobot(Robot* r){
    if(this->map[r->getCol()][r->getRow()]==1){
        cout<<"Invalid location \n";
        return false;
    }
    robot.push_back(r);
    size++;
    return true;

}
bool Map::deleteRobot(int robotnum){
    bool iscon= true;
    for(int i=0;i<robot.size();i++){
        if(this->robot[i]->getRobotId()==robotnum){
            if(this->robot[i]->getRow()==-1)iscon= false;
            if(robot[i])
                delete robot[i];
            robot.erase(robot.begin()+i);
            size--;
            return iscon;
        }
    }
    return false;

}
Map Map::operator+(const Map& map2)const{
    Map m;
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(this->map[i][j]==1|| map2.map[i][j]==1)
                m.map[i][j]= 1;
            else{
                m.map[i][j]= 0;
            }
        }
    }
    Robot* r;
    for(int i=0;i<size;i++){
        if(m.map[robot[i]->getCol()][this->robot[i]->getRow()]==0 ){
            r= new Robot(*this->robot[i]);
            m.addRobot(r);
        }
    }
    for(int i=0;i<map2.size;i++){
        if(m.map[map2.robot[i]->getCol()][map2.robot[i]->getRow()]==0 ){
            r= new Robot(*map2.robot[i]);
            m.addRobot(r);
        }
    }
    cout<<m;


    return m;
}
void Map::operator+=(const Map& map2){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(map2.map[i][j]==1){
                this->map[i][j]=1;
            }

        }
    }
    for(int r=0;r<robot.size();r++){
        if(this->map[robot[r]->getCol()][robot[r]->getRow()]==1){
            deleteRobot(this->robot[r]->getRobotId());
        }
    }

}
Map& Map::operator=(const Map& map2){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            this->map[i][j]=map2.map[i][j];
        }
    }
    for(int r=0;r<robot.size();r++){
        if(this->map[robot[r]->getCol()][robot[r]->getRow()]==1){
            deleteRobot(this->robot[r]->getRobotId());
        }
    }
    return *this;

}
bool Map::operator==(const Map& map2)const{
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(this->map[i][j]!=map2.map[i][j]){
                return false;
            }
        }
    }
    return true;

}

ostream& operator<<(ostream& out,const Map& map2 ){
    for(int i=6;i>=0;i--){
        out<<"[";
        for(int j=0;j<7;j++){
            if(j==6)
                out<<map2.map[i][j];
            else
                out<<map2.map[i][j]<<" ";
        }
        out<<"]\n";
    }
    out<<"\n";
    for(int i=0;i<map2.size;i++){
        if(map2.robot[i]->getRow()!=-1)
            cout<<"Robot:";
        cout<<*map2.robot[i];
    }
    return out;
}
