
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

bool Sudoku_Solver::_checkColumn(int index)
{
	int column = index % 9;
	unordered_set<int> occurred;
	for (int i = column; i <= column + 9 * 8; i = i + 9)
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

bool Sudoku_Solver::_checkSquare(int index);
{
	int row = index / 9;
	int column = index % 9;
	int sqRow = row - row % 3;
	int sqColumn = column - column % 3;

	int chIndex;

	unordered_set<int> occurred;
	for (int i = 0; i < 3; i++)//row
	{
		for (int j = 0; j < 3; j++)//column
		{
			chIndex = (sqRow + i) * 9 + (sqColumn + j);
			if (occurred.find(this->sudoku[i]) != occured.end())
			{
				return false;
			}
			else
			{
				occurred.insert(this->sudoku[i]);
			}
		}
	}
	return true;
}