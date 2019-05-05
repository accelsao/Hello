#include "sudoku.h"


void Sudoku::InitCover() {
	int index = 0;
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++) {
			if (board[i][j]) {
				bool done = 0;
				Node* Col = HeadNode->right;
				while (Col != HeadNode && !done) {
					Node* cur = Col->down;
					while (cur != Col && !done) {
						if (cur->cell_ID[0] == board[i][j] &&
							cur->cell_ID[1] == i + 1 &&
							cur->cell_ID[2] == j + 1) {
							coverColumn(Col);
							Node* cell = cur->right;
							while (cell != cur) {
								coverColumn(cell->head);
								cell = cell->right;
							}
							done = 1;
						}
						cur = cur->down;
					}
					Col = Col->right;
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

	// Create Columns
	for (int i = 0; i < Colcs; i++) {
		Node* newNode = new Node;
		newNode->size = 0;
		newNode->up = newNode;
		newNode->down = newNode;
		newNode->head = newNode;
		newNode->right = header;
		newNode->left = temp;
		temp->right = newNode;
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
				// insert new Node between prev and prev->right
				// prev - newNode - prev->right
				newNode->left = prev;
				newNode->right = prev->right;
				newNode->left->right = newNode;
				newNode->right->left = newNode;

				// insert newNode to top and top->up
				newNode->head = top;
				newNode->up = top->up;
				newNode->down = top;
				
				newNode->up->down = newNode;		
				newNode->down->up = newNode;
				top->size++;
				// top->down = the first newNode, then we can iterate easily
				if (top->down == top) {
					top->down = newNode;
				}
				prev = newNode;
				top = top->right;
			}
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
	count = 1;
	x = 0;
	// Constraint#3 each col 1 ~ 9
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
void Sudoku::search(int k) {
	// Selecting a column with a low node count is a heuristic which improves performance in some cases, but is not essential to the algorithm. Ref: wiki/Dancing_Links
	Node* col = HeadNode->right;
	Node* tmp = col->right;
	while (tmp != HeadNode) {
		if (tmp->size < col->size) {
			col = tmp;
		}
		tmp = tmp->right;
	}
	coverColumn(col);

	tmp = col->down; // row
	while (tmp != col) {
		//sol[k] = tmp;

		Node* cell = tmp->right;
		while (cell != tmp) {
			coverColumn(cell);
			cell = cell->right;
		}
		
		search(k + 1);

		/*tmp = sol[k];
		sol[k] = NULL;*/
		cell = tmp->left;
		while (cell != tmp) {
			uncoverColumn(cell);
			cell = cell->left;
		}

		tmp = tmp->down;
	}
	uncoverColumn(col);

}


int main() {
	Sudoku s;
	//s.readBoard();
	//s.printBoard();
	//s.BuildSparseMatrix();
	//s.BuildLinkedList();
	//s.InitCover();

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