#include "grid.h"

Sudoku_Square::Sudoku_Square()
{
    this->setSize({this->SIZE, this->SIZE});
    this->setOrigin(this->getSize().componentWiseDiv({2, 2})); //    size/2, size/2 set as origin
}

void Sudoku_Square::squareClicked(Sudoku_Square *arr, int index)
{
    if (index >= 82)
    {
        if (SELECTED >=82)
            return;
        arr[SELECTED].setFillColor({25, 25, 25});
        SELECTED = 82;
        return;
    }
    if (index < 0) index += 81;
    if (Sudoku_Square::SELECTED < 82)
        arr[Sudoku_Square::SELECTED].setFillColor({25, 25, 25});
    Sudoku_Square::SELECTED = index;
    arr[Sudoku_Square::SELECTED].setFillColor({230, 230, 230, 10});
}
