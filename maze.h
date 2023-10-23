#include <iostream> 
 #include <stack> 
 #include <vector> 
 #pragma once 
  
 using namespace std; 
  
  
 class cell {
public:
    bool WallNorth;
    bool WallEast;
    bool WallSouth;
    bool WallWest;
    bool Visited;

    cell() : WallNorth(true), WallEast(true), WallSouth(true), WallWest(true), Visited(false){};
};

class coordinate{
public:
	int x;
	int y;
	
	coordinate(int inx, int iny) : x(inx), y(iny){};
	
};