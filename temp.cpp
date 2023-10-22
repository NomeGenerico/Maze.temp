#include "Maze.h"
#include <iostream>


int main()
{
	int SizeX, SizeY;
	cout << "Size X:";
	cin >> SizeX;
	cout << "Size y:";
	cin >> SizeY;

	vector < vector<cell> > MazeArray(SizeY, vector<cell>(SizeX,cell()));
	cout << MazeArray.capacity() << endl;
	cout << MazeArray[1][1].WallSouth << endl;
	








}
