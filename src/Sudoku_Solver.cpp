
#include "Sudoku_Solver.h"
#include <unordered_set>
using std::unordered_set;
using std::array;
Sudoku_Solver::Sudoku_Solver(array<int, 81> arr) : _sudoku(arr)
{
	std::cout << "Created" << '\n';
}
Sudoku_Solver::~Sudoku_Solver() { std::cout << "Distroyed" }

bool Sudoku_Solver::_checkRow(int index)
{
	int row = index / 9;
	unordered_set<int> occurred;
	for (int i = row * 9; i < (row + 1) * 9; i++)
	{
		if (occurred.find(this->sudoku[i]) != occured.end())
		{
			return false;
		}
		else
		{
			occurred.insert(this->sudoku[i]);
		}
	}
	return true;
}