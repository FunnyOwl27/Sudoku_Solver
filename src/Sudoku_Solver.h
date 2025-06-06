#pragma once
#import <array>
class Sudoku_Solver
{
private:
	std::array<int, 81> _sudoku;
	bool _checkRow(int index);
	bool _checkColumn(int index);
	bool _checkSquare(int index);
public:
	Sudoku_Solver(std::array<int, 81>);
	~Sudoku_Solver();
	void solve();
};