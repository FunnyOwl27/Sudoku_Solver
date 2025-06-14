#include "grid.h"

Sudoku_Square::Sudoku_Square()
{
    this->setSize({this->SIZE, this->SIZE});
    this->setOrigin(this->getSize().componentWiseDiv({2,2}));//    size/2, size/2 set as origin
}

/*void Sudoku_Square::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(vertices, states);
}*/
