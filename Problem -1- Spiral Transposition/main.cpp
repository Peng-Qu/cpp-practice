/*
 * This is the c++ code for the "Spiral Transposition" problem
 * which makes use of 2D array and recursion
 */

#include <iostream>
using namespace std;

const int MAX_SIZE = 20;		//maximum size of row and column

void recursion (int array[][MAX_SIZE], const int m, const int n, int cycle){
	//recursive call
	if (cycle != 1) {recursion (array, m, n, cycle - 1);}

	//print across upper row of the spiral
	for (int col = cycle-1; col < (n-cycle+1); col++){
		cout << "| " << array[cycle-1][col] << " ";
	}
	//print down the RHS column of the spiral
	for (int row = cycle; row < m-cycle; row++){
		cout << "| " << array[row][n-cycle] << " ";
	}
	//avoid printing the same column twice in the last spiral of vertical rectangle
	//or same row twice in the last spiral of horizontal rectangle
	if(array[cycle-1][cycle-1] == array[cycle-1][n-cycle] ||
			array[cycle-1][cycle-1] == array[m-cycle][cycle-1]){
		return;
	}
	//print across the lower row of the spiral
	for (int col = n-cycle; col > cycle-2; col--){
			cout << "| " << array[m-cycle][col] << " ";
	}
	//print up the LHS column of the spiral
	for (int row = m-1-cycle; row > cycle-1; row--){
		cout << "| " << array[row][cycle-1] << " ";
	}
}

int main(){
	int m, n, array[MAX_SIZE][MAX_SIZE];

	cout << "Please enter the number of rows of the array:";
	cin >> m;
	cout << "Please enter the number of columns of the array:";
	cin >> n;
	cout << "Please enter the entries of the array row by row:" << endl;

	int diagonalSize = (m < n)? m : n;
	int numOfCycle = (diagonalSize+1)/2;

	//Fill up the m x n entries
	for (int row = 0; row < m; row++){
		cout << "Enter the entries for row number " << row+1 << endl;
		for (int col = 0; col < n; col++){
			cin >> array[row][col];
		}
	}

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << "| " << array[i][j] << " ";
		}
		cout << endl;
	}

	recursion (array, m, n, numOfCycle);
	return 0;
}
