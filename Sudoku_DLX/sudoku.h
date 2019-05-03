#pragma once

#include <iostream>
#include <vector>
using namespace std;


const int Size = 9;
// 81 cell with 9 number 81*9=729
// 81  constraint sets * 4
// 729 possibilities and 324 constraint sets 729 x 324 matrix
const int Rowps = 9 * 9 * 9;
const int Colcs = 4 * 9 * 9;
const int Size_2 = 9 * 9;

class Sudoku {
public:
	Sudoku() {
		board.resize(Size, vector<int>(Size));
		sparse_matrix.resize(Rowps, vector<bool>(Colcs));
	};
	void readBoard() {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) {
				cin >> board[i][j];
			}
	}
	void printBoard() {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << (j == 8 ? '\n' : ' ');
			}
	}
	void BuildSparseMatrix();
private:
	vector<vector<int>> board;
	vector<vector<bool>> sparse_matrix;
};
