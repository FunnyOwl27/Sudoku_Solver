#pragma once
#import <array>
#include <unordered_set>

class Sudoku_Solver
{
private:
	std::array<int, 81> _sudoku;
	std::unordered_set<int> _nonZero;

	static bool _checkRow(std::array<int, 81> arr, int index);
	static bool _checkColumn(std::array<int, 81> arr, int index);
	static bool _checkSquare(std::array<int, 81> arr, int index);
	static std::array<int, 81> _solver(std::array<int, 81>, int);
public:
	Sudoku_Solver(std::array<int, 81>);
	~Sudoku_Solver();
	void solve();
};