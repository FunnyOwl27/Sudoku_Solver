
#include "Sudoku_Solver.h"
#include <iostream>
#include <cassert>
#include <chrono>

using std::unordered_set;
using std::array;

Sudoku_Solver::Sudoku_Solver(array<int, 81> arr) : _sudoku(arr)
{
	for (int i = 0; i < 81; i++)
	{
		if (arr[i] != 0)
		{
			_nonZero.insert(i);
		}
	}
	//std::cout << "Created" << '\n';
}
Sudoku_Solver::~Sudoku_Solver() {}//std::cout << "Destroyed"; }

bool Sudoku_Solver::_checkRow(array<int, 81>arr, int index)
{
	int row = index / 9;
	unordered_set<int> occurred;
	for (int i = row * 9; i < (row + 1) * 9; i++)
	{
		if (arr[i]!= 0 && occurred.find(arr[i]) != occurred.end())
		{
			return false;
		}
		else
		{
			occurred.insert(arr[i]);
		}
	}
	return true;
}

bool Sudoku_Solver::_checkColumn(array<int,81>arr, int index)
{
	int column = index % 9;
	unordered_set<int> occurred;
	for (int i = column; i <= column + 9 * 8; i = i + 9)
	{
		if (arr[i] != 0 && occurred.find(arr[i]) != occurred.end())
		{
			return false;
		}
		else
		{
			occurred.insert(arr[i]);
		}
	}
	return true;
}

bool Sudoku_Solver::_checkSquare(array<int, 81>arr, int index)
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
			if (arr[chIndex] != 0 && occurred.find(arr[chIndex]) != occurred.end())
			{
				return false;
			}
			else
			{
				occurred.insert(arr[chIndex]);
			}
		}
	}
	return true;
}

void Sudoku_Solver::_solver(array<int, 81> arr, int index, bool &finished)
{	
	//std::cout << index << '\n';
	assert(index >= 0 && "negetive index reached, maybe solve not possible");
	if (index >= 81)
	{
		this->solved = arr;
		finished = true;
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		arr[index] = i;

		if (Sudoku_Solver::_checkColumn(arr, index) &&
			Sudoku_Solver::_checkRow(arr, index) &&
			Sudoku_Solver::_checkSquare(arr, index))
		{
			int next_index = index + 1;
			while (this->_nonZero.find(next_index) != this->_nonZero.end())
			{
				next_index++;
			}
			//std::cout << index << ':' << i << '\n';
			Sudoku_Solver::_solver(arr, next_index, finished);
			//std::cout << index << '\n';
			if (finished == true) return;
		}
	}
	return;
}

void Sudoku_Solver::solve()
{
	const auto start = std::chrono::steady_clock::now();
	int next_index = 0;
	bool finished = false;
	while (this->_nonZero.find(next_index) != this->_nonZero.end())
	{
		next_index++;
	}
	this->_solver(this->_sudoku, next_index, finished);
	const auto end = std::chrono::steady_clock::now();

	const std::chrono::duration<double> time_taken{ end - start };
	std::cout << time_taken.count() << '\n';
}