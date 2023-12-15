#include "Maze.h"
#include <iostream>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

static int renderCell(int x,int y)
{
    
    return 0;
}
int renderGrid()
{
    for (int i = 0; i < MazeArray.size(); i++)
    {
        for (int i = 0; i < MazeArray[0].size(); i++)
        {

        }
    }
    return 0;
}



int main()
{
    int WindowSizeX = 500;
    int WindowSizeY = 500;
    sf::RenderWindow window(sf::VideoMode(700, 700), "fuck you!", sf::Style::Default);
    window.setFramerateLimit(120);

    int SizeX, SizeY;
    std::cout << "Size X:";
    std::cin >> SizeX;
    std::cout << "Size y:";
    std::cin >> SizeY;

    std::vector<std::vector<cell>> MazeArray = std::vector<std::vector<cell>>(SizeY, std::vector<cell>(SizeX, cell()));
    std::cout << MazeArray.capacity() << std::endl;
    std::cout << MazeArray[1][1].WallSouth << std::endl;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        return 0;
    }
}
