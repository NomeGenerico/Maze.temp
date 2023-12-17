#include "Maze.h"
#include <iostream>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"

// declares variables
int SizeX, SizeY;
sf::RenderWindow window;

// initializes some variables
sf::Vector2f WallSize = sf::Vector2f(10, 2);
sf::Vector2f CellSize = sf::Vector2f(10, 10);

sf::RectangleShape Cell = sf::RectangleShape(CellSize);
sf::RectangleShape Wall = sf::RectangleShape(WallSize);
sf::RectangleShape RotatedWall = sf::RectangleShape(WallSize);


int renderCell(int x, int y, std::vector<std::vector<cell>> MazeArray)
{
    int PixelCordX = x * 10;
    int PixelCordY = y * 10;
    if (MazeArray[0][0].Visited)
    {
        Cell.setFillColor(sf::Color::Blue);
    }
    else
    {
        Cell.setFillColor(sf::Color::Green);
    }
    RotatedWall.rotate(90.f);
    Cell.setPosition(PixelCordX, PixelCordY);
    Wall.setPosition(PixelCordX, PixelCordY);
    window.draw(Cell);
    window.draw(Wall);
    window.draw(RotatedWall);
    Wall.move(8, 0);
    RotatedWall.move(0, 8);
    window.draw(Wall);
    window.draw(RotatedWall);
    return 0;
}
int renderGrid(std::vector<std::vector<cell>> MazeArray)
{
    for (int x = 0; x < MazeArray.size(); x++)
    {
        for (int y = 0; y < MazeArray[0].size(); y++)
        {
            renderCell(x,y,MazeArray);
        }
    }
    return 0;
}



int main()
{
    int WindowSizeX = 500;
    int WindowSizeY = 500;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "fuck you!", sf::Style::Default);
    window.setFramerateLimit(165);

    int SizeX, SizeY;
    std::cout << "Size X:";
    std::cin >> SizeX;
    std::cout << "Size y:";
    std::cin >> SizeY;

    std::vector<std::vector<cell>> MazeArray = std::vector<std::vector<cell>>(SizeY, std::vector<cell>(SizeX, cell()));
    std::cout << MazeArray.capacity() << std::endl;
    std::cout << MazeArray[1][1].WallSouth << std::endl;
    std::cout << MazeArray[1][1].Visited;






    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        renderGrid(MazeArray);
        renderCell(1, 1,MazeArray);
        /*
        RotatedWall.rotate(40.f);
        window.draw(Cell);
        window.draw(Wall);
        window.draw(RotatedWall);
        Wall.move(8, 0);
        RotatedWall.move(0, 8);
        window.draw(Wall);
        window.draw(RotatedWall);
        */




        window.display();
        //std::cout << ("pica");
    }
    return 0;
}
