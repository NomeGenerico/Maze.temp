#include "Maze.h" 
#include <iostream> 
  
 using namespace std; 
 int main() 
 { 
         int SizeX, SizeY; 
         cout << "Size X:"; 
         cin >> SizeX; 
         cout << "Size y:"; 
         cin >> SizeY; 
  
         vector<vector<cell>> MazeArray(SizeY, vector<cell>(SizeX));         
         cout << MazeArray[0][0].WallSouth << endl;  
         
         
       
   
   
 }