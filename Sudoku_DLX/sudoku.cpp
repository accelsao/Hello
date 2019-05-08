#include "sudoku.h"
#include <algorithm>
#include <ctime>
#include <cassert>

clock_t start_time, end_time;

void Sudoku::InitCover() {
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
			if (board[i][j]) {
				bool done = 0;
				for (Node* ColumnHead = HeadNode->right; ColumnHead != HeadNode && !done; ColumnHead = ColumnHead->right)
					for (Node* row = ColumnHead->down; row != ColumnHead && !done; row = row->down) {
						if (row->cell_ID[0] == board[i][j] &&
							row->cell_ID[1] == i + 1 &&
							row->cell_ID[2] == j + 1) {
							solution[row->cell_ID[1] - 1][row->cell_ID[2] - 1] = row->cell_ID[0];
							done = 1;
							coverColumn(ColumnHead);
							for (Node* cell = row->right; cell != row; cell = cell->right) {
								coverColumn(cell->head);
							}
						}
					}
			}
}

void Sudoku::coverColumn(Node* col) {
	// clear column
	col->left->right = col->right;
	col->right->left = col->left;
	// clear column
	Node* cur = col->down;
	while (cur != col) {
		// clear the row
		Node* cell = cur->right;
		while (cell != cur) {
			// covercell
			cell->down->up = cell->up;
			cell->up->down = cell->down;
			cell->head->size--;
			// covercell
			cell = cell->right;
		}
		// clear the row
		cur = cur->down;
	}
}
void Sudoku::uncoverColumn(Node* col) {
	Node* cur = col->up;
	while (cur != col) {
		Node* cell = cur->left;
		while (cell != cur) {
			cell->head->size++;
			cell->up->down = cell;
			cell->down->up = cell;
			cell = cell->left;
		}
		cur = cur->up;
	}
	col->left->right = col;
	col->right->left = col;
}

void Sudoku::BuildLinkedList() {

	Node* header = new Node;
	header->left = header;
	header->right = header;
	header->down = header;
	header->up = header;
	header->size = -1;
	header->head = header;
	Node* temp = header;

	// Create Columns Head
	for (int i = 0; i < Colcs; i++) {
		Node* newNode = new Node;
		newNode->size = 0;
		newNode->up = newNode;
		newNode->down = newNode;
		newNode->head = newNode;
		newNode->right = header;
		newNode->left = temp;
		newNode->left->right = newNode;
		temp = newNode;
	}
	int ID[3] = { 0, 1, 1 };// number, row, col
	for (int i = 0; i < Rowps; i++) {
		Node* top = header->right;
		Node* prev = NULL;

		if (i && (i % Size_2 == 0)) {
			ID[1]++;
			ID[2] = 1;
			ID[0] = 1;
		}
		else if (i && (i % Size == 0)) {
			ID[2]++;
			ID[0] = 1;
		}
		else {
			ID[0]++;
		}

		for (int j = 0; j < Colcs; j++) {
			if (sparse_matrix[i][j]) {
				Node* newNode = new Node;
				newNode->cell_ID[0] = ID[0];
				newNode->cell_ID[1] = ID[1];
				newNode->cell_ID[2] = ID[2];
				
				if (prev == NULL) {
					prev = newNode;
					prev->right = newNode;
				}
				//insert newNode between prev and prev->right
				newNode->left = prev;
				newNode->right = prev->right;
				newNode->left->right = newNode;
				newNode->right->left = newNode;

				// insert newNode between top and top->up
				newNode->head = top;
				newNode->up = top->up;
				newNode->down = top;
				newNode->up->down = newNode;		
				newNode->down->up = newNode;
				top->size++;

				// top->down = the first newNode, then we can iterate easily
				// top 自下而上建立, 同時top的down 指向第一個Node 
				if (top->down == top) {
					top->down = newNode;
				}
				prev = newNode;
			}
			top = top->right;
		}
	}
	HeadNode = header;
}


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
	// Constraint#3 each col 1 ~ 9
	x = 0;
	for (int j = 2 * Size_2; j < 3 * Size_2; j++) {
		for (int i = x; i < Rowps; i += Size_2) {
			sparse_matrix[i][j] = 1;
		}
		x++;
	}
	// Constraint#4 each box 1~9 box-number
	x = 0;
	for (int j = 3 * Size_2; j < Colcs; j++) {

		for (int r = 0; r < 3; r++)//row
			for (int c = 0; c < 3; c++) {//col
				sparse_matrix[r * Size_2 + c * Size + x][j] = 1;
			}
		int z = j + 1 - 3 * Size_2;
		if (z % (3 * Size) == 0) {
			x += (Size_2 + Size) * 2 + 1;
		}
		else if (z % Size == 0) {
			x += 2 * Size + 1;
		}
		else {
			x++;
		}
	}
}

bool Sudoku::test(const vector<vector<int>>& b) {
	for (int i = 0; i < 9; i++) {
		vector<int> a = b[i];
		sort(a.begin(), a.end());
		/*for (auto x : a)
			cout << x << " "; puts("");*/
		if (a != vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9})return 0;
	}
	for (int i = 0; i < 9; i++) {
		vector<int> a;
		for (int j = 0; j < 9; j++) {
			a.push_back(b[j][i]);
		}
		sort(a.begin(), a.end());
		/*for (auto x : a)
			cout << x << " "; puts("");*/
		if (a != vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9})return 0;
	}
	for (int x = 0; x < 9; x += 3)
		for (int y = 0; y < 9; y += 3) {
			vector<int> a;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++) {
					a.push_back(b[x + i][y + j]);

				}
			sort(a.begin(), a.end());
			/*for (auto x : a)
				cout << x << " "; puts("");*/
			if (a != vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9})return 0;
		}
	return 1;
}

void Sudoku::search() {
	if(HeadNode->right == HeadNode){ // Finish
		if (!test(solution)) {
			printf("Solution illegal there is some bugs!!!\n");
			printBoard(solution);
			system("PAUSE");
		}
		end_time = clock() - start_time;
		cout << "Time Elapsed: " << (float)end_time / CLOCKS_PER_SEC << " seconds.\n\n";
		cin.get(); // pause for multiple ans
		printf("Sudoku:\n");
		printBoard(solution);
		isSolved = 1;
		return;
	}

	// Selecting a column with a low node count is a heuristic which improves performance in some cases, but is not essential to the algorithm. Ref: wiki/Dancing_Links
	Node* ColumnHead = HeadNode->right;
	for (Node* tmp = ColumnHead->right; tmp != HeadNode; tmp = tmp->right) {
		if (tmp->size < ColumnHead->size) {
			ColumnHead = tmp;
		}
	}
	coverColumn(ColumnHead);
	// row
	for (Node* row = ColumnHead->down; row != ColumnHead; row = row->down) {
		solution[row->cell_ID[1] - 1][row->cell_ID[2] - 1] = row->cell_ID[0];
		for (Node* cell = row->right; cell != row; cell = cell->right) {
			coverColumn(cell->head);
		}
		search();
		for (Node* cell = row->left; cell != row; cell = cell->left) {
			uncoverColumn(cell->head);
		}
	}
	uncoverColumn(ColumnHead);

}

void Sudoku::readBoard(vector<vector<int>>& b) {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cin >> b[i][j];
		}
}

void Sudoku::printBoard(const vector<vector<int>>& b){
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			cout << b[i][j] << (j == 8 ? '\n' : ' ');
		}
}

int main() {
	Sudoku s;
	start_time = clock();
	s.readBoard(s.board);
	s.BuildSparseMatrix();
	s.BuildLinkedList();
	s.InitCover();
	s.search();
	if (!s.isSolved) {
		printf("No Solution!!!");
	}
}
/*
0 4 0 6 0 0 0 0 0
9 0 0 0 5 0 2 1 0
0 0 1 0 8 3 0 5 0
0 0 0 8 3 0 9 6 7
6 8 7 0 0 0 3 2 1
3 9 2 0 7 6 0 0 0
0 7 0 5 9 0 8 0 0
0 5 9 0 2 0 0 0 4
0 0 0 0 0 7 0 9 0

4 0 0 6 0 0 0 0 0
1 0 0 0 5 0 0 0 0
2 0 0 0 8 3 0 0 0
0 0 0 8 3 0 9 0 0
0 8 0 0 0 0 3 2 1
0 0 2 0 7 6 0 0 0
0 7 0 5 9 0 8 0 0
0 0 9 0 2 0 0 0 0
0 0 0 0 0 7 0 9 0

*/