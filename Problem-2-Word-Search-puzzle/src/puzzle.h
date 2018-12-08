#ifndef PUZZLE_H_
#define PUZZLE_H_

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

enum Direction{HORIZONTAL, VERTICAL, DIAGONAL};

struct Position{
	int row;
	int col;
};

class WordPuzzle{
	private:
		char** board;
		int size = 0;

	public:
		WordPuzzle (int size);
		~WordPuzzle();
		bool add_word(const char* word, Position pos, Direction d);
		void complete_puzzle();
		void print();
};

#endif /* PUZZLE_H_ */
