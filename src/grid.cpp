#include "grid.h"

Sudoku_Square::Sudoku_Square() : index(0), size(50)
{
    this->setOrigin({this->size / 2, this->size / 2});
    for (int i = 0; i < 4; i++)
        this->vertices[i].position = {i % 2 * size, i / 2 * size};
}

Sudoku_Square::Sudoku_Square(int index, float size) : index(index), size(size)
{
    this->setOrigin({this->size / 2, this->size / 2});
    for (int i = 0; i < 4; i++)
        this->vertices[i].position = {i % 2 * size, i / 2 * size};
}

void Sudoku_Square::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(vertices, states);
}
