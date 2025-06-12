#include "grid.h"

Sudoku_Square::Sudoku_Square() : position({0, 0}), index(0), size(600)
{
    //this->setOrigin({this->size / 2, this->size / 2});
    this->vertices[0].position = {0,0};
    this->vertices[1].position = {0,size};
    this->vertices[2].position = {size,0};
    this->vertices[3].position = {size,size}; 
    //this->setPosition(position);
}
Sudoku_Square::Sudoku_Square(sf::Vector2f position, int index, double size) : position(position), index(index), size(size)
{
    this->setOrigin({this->size / 2, this->size / 2});
    this->setPosition(position);
}

void Sudoku_Square::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(vertices, states);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    Sudoku_Square a;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(a);
        window.display();
    }
}
