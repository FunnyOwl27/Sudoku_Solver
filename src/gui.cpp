#include "gui.h"
#include "grid.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

float paddingx = SCREEN_WIDTH / 16;
float paddingy = SCREEN_HEIGHT / 12;
float Sudoku_Square::SIZE = (SCREEN_HEIGHT - 2*paddingy - 2*6 - 5*2)/9;

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window", 5);
    
    // INIT VARIABLES
    Sudoku_Square grid[81];
    for (int i = 0; i < 81; i++)
    {   
        grid[i].setFillColor({25,25,25});
        grid[i].setPosition({paddingx + grid->getSize().x/2 + i % 9 * (grid->getSize().x + 2) + ((i % 9) / 3) * 3, paddingy + grid->getSize().y/2 + i / 9 * (grid->getSize().x + 2) + ((i / 9) / 3) * 3});
    }
    
    sf::RectangleShape background(grid[80].getPosition() - grid[0].getPosition() + grid->getSize() + sf::Vector2f{10,10});
    background.setOrigin({background.getSize().x / 2, background.getSize().y / 2});
    background.setPosition(grid[4 + 4 * 9].getPosition());
    background.setFillColor({70, 70, 70});
    
    while (window.isOpen())
    {
        
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
            // mouse left button pressed event -  to select and fill numbers in grid
            if (const auto* pressed = event->getIf<sf::Event::MouseButtonReleased>())
            {
                if (pressed->button == sf::Mouse::Button::Left)
                {
                    bool Clicked_Grid = false;
                    for(int i = 0 ; i<81;i++)
                    {
                        if(grid[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(pressed->position)))
                        {
                            Clicked_Grid = true;

                            if (Sudoku_Square::SELECTED > -1)
                                grid[Sudoku_Square::SELECTED].setFillColor({25,25,25});
                            Sudoku_Square::SELECTED = i;
                            grid[Sudoku_Square::SELECTED].setFillColor({230,230,230});
                            
                            break;
                        }
                    }
                    if (!Clicked_Grid)
                    {
                        grid[Sudoku_Square::SELECTED].setFillColor({25,25,25});
                        Sudoku_Square::SELECTED = -1;
                    }
                }
            }
        }
        // DRAW STUFF
        window.clear({20, 20, 20});
        window.draw(background);
        for (const auto &i : grid)
        {
            window.draw(i);
        }
        window.display();
    }
}