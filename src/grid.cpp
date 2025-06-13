#include "grid.h"

Sudoku_Square::Sudoku_Square() : position({0, 0}), index(0), size(600)
{
    this->setOrigin({this->size / 2, this->size / 2});
    this->vertices[0].position = {0,0};
    this->vertices[1].position = {0,size};
    this->vertices[2].position = {size,0};
    this->vertices[3].position = {size,size}; 
    this->setPosition(position);
}
Sudoku_Square::Sudoku_Square(sf::Vector2f position, int index, float size) : position(position), index(index), size(size)
{
    this->setOrigin({this->size / 2, this->size / 2});
    this->vertices[0].position = {0,0};
    this->vertices[1].position = {0,size};
    this->vertices[2].position = {size,0};
    this->vertices[3].position = {size,size}; 
    this->setPosition(position);
}

void Sudoku_Square::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(vertices, states);
}

