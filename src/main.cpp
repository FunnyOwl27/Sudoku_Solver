#include "Sudoku_Solver.h"
#include <iostream>

int main()
{
    std::array<int, 81> sudoku = {
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 3, 0, 8, 5,
        0, 0, 1, 0, 2, 0, 0, 0, 0,
        0, 0, 0, 5, 0, 7, 0, 0, 0,
        0, 0, 4, 0, 0, 0, 1, 0, 0,
        0, 9, 0, 0, 0, 0, 0, 0, 0,
        5, 0, 0, 0, 0, 0, 0, 7, 3,
        0, 0, 2, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 4, 0, 0, 0, 9,
    };



	Sudoku_Solver a(sudoku);

    a.solve();

    for (int i = 0; i < 81; i++)
    {
        std::cout << a.solved[i]<< ", ";
        if (i % 9 == 8)
        {
            std::cout << '\n';
        }
    }
}