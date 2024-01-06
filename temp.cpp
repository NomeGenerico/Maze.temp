#include "Maze.h"
#include "BackTracker.h"
#include <iostream>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include <time.h>

// declares variables
int SizeX, SizeY;
sf::RenderWindow window;

int WindowSizeX;
int WindowSizeY;

sf::Vector2f WallSize;
sf::Vector2f CellSize;

sf::RectangleShape Cell;
sf::RectangleShape Wall;
sf::RectangleShape WallR;



// Doesnt Work IDKW
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
    Cell.setPosition(PixelCordX, PixelCordY);
    Wall.setPosition(PixelCordX, PixelCordY);
    window.draw(Cell);
    window.draw(Wall);
    Wall.move(8, 0);
    window.draw(Wall);
    return 0;
}
// Doesnt Work IDKW
int renderGrid(std::vector<std::vector<cell>> MazeArray)
{
    for (int x = 0; x < MazeArray.size(); x++)
    {
        for (int y = 0; y < MazeArray[0].size(); y++)
        {
            renderCell(x, y, MazeArray);
        }
    }
    return 0;
}

int mazesolver(int x, int y)
{
    return 0;
}




class Button
{
    sf::Vector2f ButtonSize = sf::Vector2f(100, 30);
    sf::RectangleShape ButtonImage = sf::RectangleShape(ButtonSize);
    int Id;
    coordinate Position;
    
    Button()
    {

        ButtonImage.setOutlineColor(sf::Color::Black);
        ButtonImage.setOutlineThickness(-2);
    }




};














int main()
{
    srand(time(nullptr));
    int WindowSizeX = 1200;
    int WindowSizeY = 800;
    sf::RenderWindow window(sf::VideoMode(WindowSizeX, WindowSizeY), "fuck jordam?", sf::Style::Default);
    window.setFramerateLimit(60);

    int SizeX, SizeY;
    std::cout << "Size X:";
    std::cin >> SizeX;
    std::cout << "Size y:";
    std::cin >> SizeY;

    // Seting Up Maze
    std::vector<std::vector<cell>> MazeArray = std::vector<std::vector<cell>>(SizeX, std::vector<cell>(SizeY, cell()));
    std::cout << MazeArray.capacity() << std::endl;
    std::cout << MazeArray[1][1].WallSouth << std::endl;


    //Size of the maze on screen
    float CellSizeInt = (WindowSizeY - (50 / SizeY)) / SizeY;
    sf::Vector2f WallSize = sf::Vector2f(CellSizeInt, 1);
    sf::Vector2f CellSize = sf::Vector2f(CellSizeInt, CellSizeInt);

    sf::RectangleShape Cell = sf::RectangleShape(CellSize);
    sf::RectangleShape Wall = sf::RectangleShape(WallSize);
    sf::RectangleShape WallR = sf::RectangleShape(WallSize);
    WallR.setRotation(90.f);
    coordinate startCord = coordinate(0, 0);
    bool MazeGenerated = false;
    bool Backtracker = true;




    std::stack <coordinate, std::deque<coordinate>> stack;
    int numVisitedCells = 1;
    bool ended = false;
    coordinate tempCord = startCord;
    MazeArray[startCord.y][startCord.x].Visited = true;

    stack.push(tempCord);





    int fuckme = 0;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        

        


        
        
        if (!MazeGenerated and Backtracker)
        {
            if (numVisitedCells == SizeX * SizeY)
            {
                MazeArray = CleanMaze(MazeArray);
                MazeGenerated = true;
            }

            // Makes cell visited, removes walls and pushes the stack
            tempCord = AdjRandomCords(SizeX, SizeY, tempCord, MazeArray);
            if (!(tempCord.x == -1) and !(tempCord.y == -1))
            {
                MazeArray[tempCord.x][tempCord.y].Visited = true;
                numVisitedCells += 1;
                MazeArray = wallremover(SizeX, SizeY, stack.top(), tempCord, MazeArray);
                stack.push(tempCord);
            }
            else
            {
                bool valid = false;

                while (!valid)
                {

                    if (stack.size() == 0)
                    {
                        MazeArray = CleanMaze(MazeArray);
                        MazeGenerated = true;
                        break;
                    }
                    stack.pop(); 
                    if (stack.size() == 0)
                    {
                        MazeArray = CleanMaze(MazeArray);
                        MazeGenerated = true;
                        break;
                    }
                    tempCord = stack.top();
                    valid = CheckNeighbors(tempCord, SizeX, SizeY, MazeArray);
                    
                    
                }
            }


            
        }
        
        if (MazeGenerated and fuckme < 1)
        {
            fuckme = 1;
            MazeArray = CleanMaze(MazeArray);
        }
        //MazeArray = CleanMaze(MazeArray);









            // works ouside the funtion
            // draws the maze
            // Sometimes Walls or The backtraking funtion Dont work as expected????
      window.clear(sf::Color::White);
      for (int x = 0; x < SizeX; x++) {
        for (int y = 0; y < SizeY; y++) {
                    int PixelCordX = x * CellSize.x + WallSize.y;
                    int PixelCordY = y * CellSize.y + WallSize.y;

                    if (MazeArray[x][y].Visited and !(x == 0 and y == 0) and !(x == SizeX - 1 and y == SizeY - 1))
                    {
                        Cell.setFillColor(sf::Color::Blue);
                    }
                    if (!(MazeArray[x][y].Visited) and !(x == 0 and y == 0) and !(x == SizeX - 1 and y == SizeY - 1))
                    {
                        Cell.setFillColor(sf::Color::Black);
                    }

                    if (x == 0 and y == 0)
                    {
                        Cell.setFillColor(sf::Color::Cyan);
                    }
                    if (x == SizeX - 1 and y == SizeY - 1)
                    {
                        Cell.setFillColor(sf::Color::Red);
                    }




                    Cell.setPosition(PixelCordX, PixelCordY);
                    Wall.setPosition(PixelCordX, PixelCordY);
                    WallR.setPosition(PixelCordX + 1, PixelCordY);
                    window.draw(Cell);
                    if (MazeArray[x][y].WallNorth)
                    {
                        window.draw(Wall);
                    }
                    if (MazeArray[x][y].WallWest)
                    {
                        window.draw(WallR);
                    }
                    Wall.move(0, CellSize.x - WallSize.y);
                    WallR.move(CellSize.y - 1, 0);
                    if (MazeArray[x][y].WallSouth)
                    {
                        window.draw(Wall);
                    }
                    if (MazeArray[x][y].WallEast)
                    {
                        window.draw(WallR);
                    }
        }
      }



            window.display();
            //std::cout << ("pica");

    }
    return 0;
}
