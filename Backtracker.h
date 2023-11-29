#pragma once

#include "Maze.h" 
#include <iostream> 


bool CheckNeighbors(coordinate Old, int SizeX, int SizeY)
{
	bool valid = true;
	int shift = 1;

	if (Old.x + shift < 0 or Old.x + shift > SizeX or MazeArray[Old.x + shift][Old.y].Visited)
	{
		shift = shift * -1;
		if (Old.x + shift < 0 or Old.x + shift > SizeX or MazeArray[Old.x + shift][Old.y].Visited)
		{
			valid = false;
		}
		valid = false;
	}

	if (Old.y + shift < 0 or Old.y + shift > SizeY or MazeArray[Old.x][Old.y + shift].Visited)
	{
		shift = shift * -1;
		if (Old.y + shift < 0 or Old.y + shift > SizeY or MazeArray[Old.x][Old.y + shift].Visited)
		{
			valid = false;

		}
		valid = false;
	}
	return valid;
}

coordinate AdjRandomCords(int SizeX, int SizeY, coordinate Old)
{
	bool horizontal;
	int randomint;
	int shift;

	coordinate newcord{ Old.x, Old.y };

	if (
		MazeArray[Old.x + 1][Old.y].Visited == true and
		MazeArray[Old.x - 1][Old.y].Visited == true and
		MazeArray[Old.x][Old.y + 1].Visited == true and
		MazeArray[Old.x][Old.y - 1].Visited == true
		)
	{
		Old.x = -1;
		Old.y = -1;
		return Old;
	}

	randomint = rand() / 1;

	if (randomint % 2 == 0) { horizontal = true; }

	else { horizontal = false; }

	randomint = rand();

	if (randomint % 2 == 0) { shift = 1; }

	else { shift = -1; }


	bool valid = false;

	int count = 0;
	while (!valid)
	{

		if (horizontal)
		{
			if (Old.x + shift < 0 or Old.x + shift > SizeX or MazeArray[Old.x + shift][Old.y].Visited)
			{
				shift = shift * -1;
				if (Old.x + shift < 0 or Old.x + shift > SizeX or MazeArray[Old.x + shift][Old.y].Visited)
				{
					horizontal = false;

				}
			}
		}
		if (!horizontal)
		{
			if (Old.y + shift < 0 or Old.y + shift > SizeY or MazeArray[Old.x][Old.y + shift].Visited)
			{
				shift = shift * -1;
				if (Old.y + shift < 0 or Old.y + shift > SizeY or MazeArray[Old.x][Old.y + shift].Visited)
				{
					horizontal = true;

				}
			}
		}
		count += 1;
		if (count > 5)
		{
			Old.x = -1;
			Old.y = -1;
			return Old;
		}
	}
	if (horizontal)
	{
		newcord.x = Old.x + shift;
	}
	else
	{
		newcord.y = Old.y + shift;
	}
	return newcord;
}

void wallremover(int SizeX, int SizeY, coordinate cord1, coordinate cord2)
{
	// 4 and 2 are oposites and 1 and 3 are too
	
	int difx ; 
	int dify ;
	difx = cord2.x - cord1.x;
	dify = cord2.y - cord1.y;
	if (difx == 1)
	{
		MazeArray[cord2.x][cord2.y].RemoveWall(4);
		MazeArray[cord1.x][cord1.y].RemoveWall(2);
	}
	if (difx == -1)
	{
		MazeArray[cord2.x][cord2.y].RemoveWall(2);
		MazeArray[cord1.x][cord1.y].RemoveWall(4);
	}
	if (dify == 1)
	{
		MazeArray[cord2.x][cord2.y].RemoveWall(1);
		MazeArray[cord1.x][cord1.y].RemoveWall(3);
	}
	if (dify == -1)
	{
		MazeArray[cord2.x][cord2.y].RemoveWall(3);
		MazeArray[cord1.x][cord1.y].RemoveWall(1);
	}


}

void Backtracking(coordinate startCord, int SizeX, int SizeY)
{
	std::stack <coordinate, std::deque<coordinate>> stack;
	int numVisitedCells = 1;
	bool ended = false;
	coordinate tempCord{0,0};
	MazeArray[startCord.y][startCord.x].Visited = true;
	stack.push(tempCord);
	while (!ended)
	{
		// checks if every square benn filled
		if (numVisitedCells == SizeX * SizeY)
		{
			return;
		}

		// checks if it has valid neighbors and pop it to the latest valid
		tempCord = AdjRandomCords(SizeX, SizeY, startCord);
		if (tempCord.x == -1)
		{
			bool valid = false;

			stack.pop();
			

			while (!valid)
			{
				tempCord = stack.top();
				valid = CheckNeighbors(tempCord, SizeX, SizeY);
				if (!valid)
				{
					stack.pop();
				}
			}
		}
		
		// Makes cell visited, removes walls and pushes the stack
		MazeArray[tempCord.x][tempCord.y].Visited = true;
		numVisitedCells += 1;
		wallremover(SizeX, SizeY, stack.top(), tempCord);
		stack.push(tempCord);


	}
}


