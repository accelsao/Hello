#include "sudoku.h"


void Sudoku::BuildSparseMatrix() {
	// sparse_matrix row order, RowColNumber
	// col order constrint 1 ~ 4

	// Constraint#1 one value each cell
	int j = 0, count = 0;
	for (int i = 0; i < Rowps; i++) {
		sparse_matrix[i][j] = 1;
		count++;
		if (count >= Size) {
			count = 0;
			j++;
		}
	}
	// Constraint#2 each row 1 ~ 9
	int x = 0;
	count = 1;
	for (int j = Size_2; j < 2 * Size_2; j++) {
		for (int i = x; i < count * Size_2; i += Size) {
			sparse_matrix[i][j] = 1;
		}
		if ((j + 1) % Size == 0) {// finish 1~9 next row
			x = count * Size_2;
			count++;
		}
		else { // next number
			x++;
		}
	}
	count = 1;
	x = 0;
	// Constraint#3 each col 1 ~ 9
	for (int j = 2 * Size_2; j < 3 * Size_2; j++) {
		for (int i = x; i < Rowps; i += Size_2) {
			sparse_matrix[i][j] = 1;
		}
		x++;
	}

}

int main() {
	Sudoku s;
	//s.readBoard();
	//s.printBoard();
	s.BuildSparseMatrix();
}
/*
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
*/