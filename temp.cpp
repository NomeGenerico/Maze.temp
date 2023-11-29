#include "Maze.h"
#include <iostream>






int main()


	int SizeX, SizeY;
	std::cout << "Size X:";
	std::cin >> SizeX;
	std::cout << "Size y:";
	std::cin >> SizeY;

	MazeArray = std::vector<std::vector<cell>>(SizeY, std::vector<cell>(SizeX, cell()));
	std::cout << MazeArray.capacity() << std::endl;
	std::cout << MazeArray[1][1].WallSouth << std::endl;
	




}
