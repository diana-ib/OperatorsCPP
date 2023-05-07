//
// Created by ise on 1/1/23.
//
#include "Map.h"
#include "Robot.h"
#include "Game.h"
#include <iostream>
using namespace std;
Game::Game(){
       int Map1[7][7] ={{1,0,0,0,0,0,0},
                        {1,0,1,0,0,1,0},
                        {1,0,1,1,0,1,0},
                        {0,0,0,1,1,1,0},
                        {0,1,0,1,1,1,0},
                        {1,1,0,0,0,0,1},
                        {1,0,0,1,1,0,1}};

       int Map2[7][7] ={{1,0,1,0,0,0,0},
                        {1,1,0,1,1,1,0},
                        {0,0,0,0,0,1,1},
                        {0,1,1,1,0,1,1},
                        {1,1,0,0,0,1,1},
                        {1,1,0,1,1,1,1},
                        {1,1,0,1,1,1,1}};
       map1=Map(Map1,1);
       map2=Map(Map2,2);
       menu();
}
Game::~Game(){

}
void Game::menu(){
    char input=-1;
    bool done= true;
    while(done) {
        cout << "Robot Control Menu\n"
                "1. Add Robot\n"
                "2. Delete Robot\n"
                "3. Move Robot\n"
                "4. Operator +\n"
                "5. Operator +=\n"
                "6. Operator =\n"
                "7. Operator ==\n"
                "8. Operator <<\n"
                "9. Quit\n"
                "Input your option:\n";
        cin >> input;
        Robot *robot1;
        Map m;
        int robotNum, mapNum, r, c;
        char d;
        char cr[30];
        bool isValid;
        switch (input) {
            case '1':
                cout << "Enter MAP number: " << endl;
                cin >> mapNum;
                if (mapNum > 2 || mapNum < 1) {
                    cout << "Invalid MAP number\n";
                    break;
                }
                cout << "Enter Coordinates (X,Y): \n";
                scanf(" %[^\n]s", cr);
                c = atoi(&cr[0]);
                r = atoi(&cr[2]);
                if (c < 0 || r < 0 || c > 6 || r > 6) {
                    cout << "Invalid location"<<endl;
                    break;
                } else {
                    robot1 = new Robot(c, r, mapNum);
                    allRobots.push_back(robot1);
                    if (mapNum == 1) {
                        isValid=map1.addRobot(robot1);
                        if(!isValid){
                            Robot::down();
                            delete robot1;
                            break;
                        }
                        cout << "New Robot:";
                        cout<<*robot1;
                    }
                    if (mapNum == 2) {
                        isValid=map2.addRobot(robot1);
                        if(!isValid){
                            Robot::down();
                            delete robot1;
                            break;
                        }
                        cout << "New Robot:";
                        cout <<*robot1;
                    }
                }
                break;

            case '2':
                cout << "Enter Robot number: \n";
                cin >> robotNum;
                robot1=nullptr;
                for (auto & allRobot : allRobots) {
                    if (robotNum == allRobot->getRobotId()) {
                        robot1 = allRobot;
                        mapNum = allRobot->getMapNum();
                    }
                }
                if (mapNum == 1) {
                    isValid=(robot1->getRow()!=-1);
                    if(isValid)
                        cout << "Robot deleted: ";
                    cout <<*robot1;
                    allRobots.erase(allRobots.begin()+robotNum-1);
                }
                if (mapNum == 2) {
                    isValid=(robot1->getRow()!=-1);
                    if(isValid)
                        cout << "Robot deleted: ";
                    cout <<*robot1;
                    map2.deleteRobot(robotNum);
                    allRobots.erase(allRobots.begin()+robotNum-1);

                }
                break;

            case '3':
                cout << "Enter Robot number: \n";
                cin >> robotNum;
                cout<< "Enter Direction: \n";
                cin>>d;
                for (auto & allRobot : allRobots) {
                    if (robotNum == allRobot->getRobotId()) {
                        isValid=allRobot->moveRobot(d);
                        if(!isValid)break;
                        cout<<"Robot: ";
                        cout <<*allRobot;
                    }
                }
                break;
            case '4':
                map1+map2;
                break;
            case '5':
                cout<<"Override MAP number: \n";
                cin >> mapNum;
                if (mapNum > 2 || mapNum < 1) {
                    cout << "Invalid MAP number\n";
                    break;
                }
                if(mapNum==1){
                    map1+=map2;
                }
                if(mapNum==2)
                    map2+=map1;

                break;
            case '6':
                cout<<"Override MAP number: \n";
                cin >> mapNum;
                if (mapNum > 2 || mapNum < 1) {
                    cout << "Invalid MAP number\n";
                    break;
                }
                if(mapNum==1){
                    map1=map2;
                }
                if(mapNum==2)
                    map2=map1;
                break;
            case '7':
                if((map1==map2)){
                    cout<<"TRUE\n";
                } else
                    cout<<"FALSE\n";
                break;
            case '8':
                cout<<"Please enter MAP number: \n";
                cin>>mapNum;
                if(mapNum > 2 || mapNum < 1) {
                cout << "Invalid MAP number\n";
                break;
                }
                if(mapNum==1){
                    cout<<map1;
                }
                if(mapNum==2)
                    cout<<map2;
                break;
            case '9':
                done=false;
                break;
            default:
                cout << "Invalid input\n";

        }
    }
}
int main() {
Game game;
return 0;
}