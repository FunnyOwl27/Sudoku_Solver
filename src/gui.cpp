#include "gui.h"
#include "grid.h"
#include "Sudoku_Solver.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

float paddingx = SCREEN_WIDTH / 16;
float paddingy = SCREEN_HEIGHT / 12;
float Sudoku_Square::SIZE = (SCREEN_HEIGHT - 2 * paddingy - 2 * 6 - 5 * 2) / 9;
sf::Font Sudoku_Square::FONT("../../assets/IBMPlexMono-Regular.ttf");

int main() 
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window", 5);

    // INIT VARIABLES
    Sudoku_Square grid[81];
    for (int i = 0; i < 81; i++)
    {
        grid[i].setFillColor({25, 25, 25});
        grid[i].setPosition({paddingx + grid->getSize().x / 2 + i % 9 * (grid->getSize().x + 2) + ((i % 9) / 3) * 3, paddingy + grid->getSize().y / 2 + i / 9 * (grid->getSize().x + 2) + ((i / 9) / 3) * 3});
    }

    sf::RectangleShape background(grid[80].getPosition() - grid[0].getPosition() + grid->getSize() + sf::Vector2f{10, 10});
    background.setOrigin({background.getSize().x / 2, background.getSize().y / 2});
    background.setPosition(grid[4 + 4 * 9].getPosition());
    background.setFillColor({70, 70, 70});

    sf::RectangleShape solve({SCREEN_WIDTH - (2 * paddingx + Sudoku_Square::SIZE/2 + 5 + grid[4 * 9 + 8].getPosition().x), Sudoku_Square::SIZE*2});
    solve.setOrigin(solve.getSize().componentWiseDiv({2,2}));
    solve.setPosition(grid[4*9 + 8].getPosition() + sf::Vector2f{paddingx + Sudoku_Square::SIZE/2 + 5 + solve.getSize().x/2, 0});
    solve.setFillColor(Sudoku_Square::Color::SolvedText);

    sf::RectangleShape clear(solve.getSize());
    clear.setOrigin(clear.getSize().componentWiseDiv({2,2}));
    clear.setPosition(grid[7*9 + 8].getPosition() + sf::Vector2f{paddingx + Sudoku_Square::SIZE/2 + 5 + solve.getSize().x/2, 0});
    clear.setFillColor(sf::Color::Red);
    
    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
            // mouse left button pressed event -  to select and fill numbers in grid
            if (const auto *mouseButtonPressed = event->getIf<sf::Event::MouseButtonReleased>())
            {
                if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                {
                    bool clicked_Grid = false;
                    for (int i = 0; i < 81; i++)
                    {
                        if (grid[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mouseButtonPressed->position)))
                        {
                            clicked_Grid = true;

                            Sudoku_Square::squareClicked(grid, i);

                            break;
                        }
                    }
                    if (!clicked_Grid)
                    {
                        Sudoku_Square::squareClicked(grid, 82);
                    }
                    if (solve.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouseButtonPressed->position)))
                    {
                        Sudoku_Solver a(Sudoku_Square::sudokuToArray(grid));
                        a.solve();
                        for(int i = 0; i < 81; i++)
                        {
                            if (grid[i].value == 0)
                            {
                                grid[i].value = a.solved[i];
                                grid[i].textColor = Sudoku_Square::Color::SolvedText;
                            }
                        }
                    }
                    if (clear.getGlobalBounds().contains(static_cast<sf::Vector2f>(mouseButtonPressed->position)))
                    {
                        for(auto &i : grid)
                        {
                            i.value = 0;
                            i.textColor = Sudoku_Square::Color::InputText;
                        }
                    }
                }
            }
            if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::W || keyPressed->code == sf::Keyboard::Key::Up)
                {
                    if (Sudoku_Square::SELECTED < 82)
                        Sudoku_Square::squareClicked(grid, (Sudoku_Square::SELECTED - 9) % 81);
                    else
                        Sudoku_Square::squareClicked(grid, 0);
                }
                else if (keyPressed->code == sf::Keyboard::Key::A || keyPressed->code == sf::Keyboard::Key::Left)
                {
                    if (Sudoku_Square::SELECTED < 82)
                        Sudoku_Square::squareClicked(grid, (Sudoku_Square::SELECTED - 1) % 81);
                    else
                        Sudoku_Square::squareClicked(grid, 0);
                }
                else if (keyPressed->code == sf::Keyboard::Key::D || keyPressed->code == sf::Keyboard::Key::Right)
                {
                    if (Sudoku_Square::SELECTED < 82)
                        Sudoku_Square::squareClicked(grid, (Sudoku_Square::SELECTED + 1) % 81);
                    else
                        Sudoku_Square::squareClicked(grid, 0);
                }
                else if (keyPressed->code == sf::Keyboard::Key::S || keyPressed->code == sf::Keyboard::Key::Down)
                {
                    if (Sudoku_Square::SELECTED < 82)
                        Sudoku_Square::squareClicked(grid, (Sudoku_Square::SELECTED + 9) % 81);
                    else
                        Sudoku_Square::squareClicked(grid, 0);
                }
                Sudoku_Square::numberInput(grid, keyPressed->code);
            }
        }
        // DRAW STUFF
        window.clear({20, 20, 20});
        window.draw(background);
        for (const auto &i : grid)
        {
            window.draw(i);
        }
        window.draw(solve);
        window.draw(clear);
        window.display();
    }
}