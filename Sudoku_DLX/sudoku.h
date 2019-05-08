#pragma once

#include <iostream>
#include <vector>
using namespace std;

// To make life easy, I implement for 9x9 matrix only

const int Size = 9;
// 81 cell with 9 number 81*9=729
// 81  constraint sets * 4
// 729 possibilities and 324 constraint sets 729 x 324 matrix
const int Rowps = 9 * 9 * 9;
const int Colcs = 4 * 9 * 9;
const int Size_2 = 9 * 9;


struct Node {
	Node* left;
	Node* right;
	Node* up;
	Node* down;
	Node* head;

	int size; // column header
	int cell_ID[3]; //ID Format: (Number, Row, Column)
};

class Sudoku {
public:
	Sudoku() {
		board.resize(Size, vector<int>(Size));
		solution.resize(Size, vector<int>(Size));
		sparse_matrix.resize(Rowps, vector<bool>(Colcs));
		HeadNode = NULL;
		isSolved = false;
	};
	
	void BuildSparseMatrix();
	void search();
	void readBoard(vector<vector<int>>& b);
	void printBoard(const vector<vector<int>>& b);
	void BuildLinkedList();
	void InitCover();
	void coverColumn(Node* col);
	void uncoverColumn(Node* col);
	bool isSolved;
	vector<vector<int>> board;
	vector<vector<int>> solution;
	bool test(const vector<vector<int>>& b);
private:
	vector<vector<bool>> sparse_matrix;
	Node* HeadNode;
};
