#include "puzzle.h"
using namespace std;

WordPuzzle::WordPuzzle (int size){
	this->board = new char*[size];
	for (int row = 0; row < size; row++){
		this->board[row] = new char[row+1];
		for (int col = 0; col < row + 1; col++){
			board[row][col] = '_';
		}
	}
	this->size = size;
}

WordPuzzle::~WordPuzzle(){
	for (int row = 0; row < size; row++){
		delete [] board[row];
	}
	delete[] board;
}

bool WordPuzzle::add_word(const char* word, Position pos, Direction d){
	int len = strlen(word);
	if (d == HORIZONTAL){
		if ((len + (pos.col)) > ((pos.row)+1)){
			cout << "Invalid add! Please enter again." << endl;
			return false;
		}
		for (int i = 0; i < len; i++){
			if (board[pos.row][(pos.col)+i] != '_'){
				cout << "Invalid add! Please enter again." << endl;
				return false;
			}else{
				board[pos.row][(pos.col)+i] = word[i];
			}
		}
		cout << endl;
	}
	if (d == VERTICAL){
		if ((len + (pos.row)) > size){
			cout << "Invalid add! Please enter again." << endl;
			return false;
		}
		for (int i = 0; i < len; i++){
			if (board[(pos.row)+i][pos.col] != '_'){
				cout << "Invalid add! Please enter again." << endl;
				return false;
			}
			else{
				board[(pos.row)+i][pos.col] = word[i];
			}
		}
		cout << endl;
	}
	if (d == DIAGONAL){
		if (len + (pos.row) > size){
			cout << "Invalid add! Please enter again." << endl;
			return false;
		}
		for (int i = 0; i < len; i++){
			if (board[(pos.row)+i][(pos.col)+i] != '_'){
				cout << "Invalid add! Please enter again." << endl;
				return false;
			}else{
				board[(pos.row)+i][(pos.col)+i] = word[i];
			}
		}
		cout << endl;
	}
	return true;
}

void WordPuzzle::complete_puzzle(){
	for (int row = 0; row < size; row++){
		for (int col = 0; col <= row; col++){
			if (board[row][col] == '_'){
				board[row][col] = rand()% 26 + 97;
			}
		}
	}
}

void WordPuzzle::print(){
	for (int row = 0; row < size; row++){
		for (int col = 0; col <= row; col++){
			cout << board[row][col] << ",";
		}
		cout << endl;
	}
}
