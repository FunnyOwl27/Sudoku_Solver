#include "Sudoku_Solver.h"


int main()
{
	std::array<int,81> sudoku = {
    7, 6, 0, 1, 9, 0, 3, 8, 0,
    0, 9, 3, 0, 7, 4, 0, 6, 2,
    0, 3, 0, 0, 0, 0, 4, 0, 0,
    0, 2, 7, 0, 5, 0, 9, 6, 3,
    9, 0, 5, 4, 0, 0, 0, 0, 0,
    0, 8, 0, 9, 0, 7, 0, 5, 0,
    8, 0, 1, 2, 0, 6, 0, 0, 0,
    0, 0, 0, 0, 1, 7, 2, 0, 6,
    0, 0, 0, 7, 4, 0, 0, 9, 0
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