#include "gui.h"
#include "grid.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window", 5);

    // INIT VARIABLES

    Sudoku_Square grid[81];
    float paddingx = grid->size / 2 + SCREEN_WIDTH / 16;
    float paddingy = grid->size / 2 + SCREEN_HEIGHT / 12;
    for (int i = 0; i < 81; i++)
    {
        grid[i].setPosition({paddingx + i % 9 * (grid[i].size + 5), paddingy + i / 9 * (grid[i].size + 5)});
    }
    sf::RectangleShape background({8 * (grid[0].size + 5) + grid->size + 10, 8 * (grid[0].size + 5) + grid->size + 10});
    background.setOrigin({background.getSize().x/2 , background.getSize().y/2});
    background.setPosition(grid[4 + 4 * 9].getPosition());
    background.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        // DRAW STUFF
        window.clear();
        window.draw(background);
        for (const auto &i : grid)
        {
            window.draw(i);
        }
        window.display();
    }
}