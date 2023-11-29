#pragma once 

#include <iostream> 
#include <stack> 
#include <vector> 




class cell {
public:
    bool WallNorth;
    bool WallEast;
    bool WallSouth;
    bool WallWest;
    bool Visited;

    cell() : WallNorth(true), WallEast(true), WallSouth(true), WallWest(true), Visited(false) {};

    void RemoveWall(int wall)
    {
        switch (wall)
        {
        case(1):
            WallNorth = false;
        case(2):
            WallEast = false;
        case(3):
            WallSouth = false;
        case(4):
            WallWest = false;
        default:
            break;
        }
    }
};

class coordinate {
public:
    int x;
    int y;

    coordinate(int inx, int iny) : x(inx), y(iny) {};

};

extern std::vector<std::vector<cell>> MazeArray;
