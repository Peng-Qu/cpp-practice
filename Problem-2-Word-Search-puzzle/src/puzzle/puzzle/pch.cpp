// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include <cstring>
#include <iostream>
#include <sstream>
#include <time.h>  
#include <stdlib.h> 
#include "pch.h"

using namespace std;
namespace PCH {
	//Constuctor, initialize the board
	PuzzleApp::PuzzleApp(const int puzzleSz)
	{
		puzzleSize = puzzleSz;		
		for (int i = 0; i < puzzleSize*(puzzleSize + 1) / 2; i++) {
			board+='_';
		}
	}

	// destructor
	PuzzleApp::~PuzzleApp()
	{
	}



	/* the menu 
	*/
	int PuzzleApp::menu(){
		int i;
		cout << "Please choose one of the followings:\n0. Quit the program\n1. Add a word\n2. Print the puzzle\n3. Complete the puzzle" << endl << "> ";
		cin >> i;
		if (i < 0 || i>3 || cin.fail()) i = -1;
		cin.clear();
		cin.ignore(2000, '\n');
		cout << endl;
		return i;
	}

	/* menu 2 print the puzzle
	*/
	void PuzzleApp::printPuzzle()
	{
		int index = 0;
		for (int i = 1; i < puzzleSize+1; i++) {
			for (int j = 0; j < i; j++) {
				cout << board[index++] << ',';

			}
			cout << endl;
		}
	}

	/*menu 3 complete the puzzle
	*/
	void PuzzleApp::completePuzzle()
	{
		srand((unsigned)time(NULL));
		int index = 0;
		for (int i = 0; i < (puzzleSize + 1)*puzzleSize / 2; i++) {
			if (board[index]=='_') {
				board[index]= char(97+ rand() % 26);
			}
			index++;
		}
	}
	/*nemu 1 add word. split the row and column, calculate the index of the board of the word
	*/
	void PuzzleApp::addWord(string word,string position,const int direction)
	{
		int index = 0;
		int row = atoi(position.substr(0, position.find(" ")).c_str());
		int column =atoi(position.substr(position.find(" ")+1).c_str());

		for (int i = 1; i < row + 1; i++) {
			index += i;
		}
		index += column;
		switch (direction)
		{
			//0:horizontal
		case 0:
			for (unsigned int i = 0; i < word.length(); i++) {
				board[index++] = word[i];
			}
			break;
			//1:vertical
		case 1:
			for (unsigned int i = 0; i < word.length(); i++) {
				board[index] = word[i];
				index += ++row;
			}
			break;
			// 2:diagonal
		case 2:
			for (unsigned int i = 0; i < word.length(); i++) {
				board[index] = word[i];
				index += ++row + 1;
			}
			break;
		default:
			cout << "\n===Invalid Selection, try again===\n" << endl;
			break;
		}
	}


	//the interface
	void PuzzleApp::run()
	{
		int s;
		string  word , position;
		int direction;

		do {
			s = menu();
			switch (s)
			{
			case 0:
				cout << "\nGoodbye!!" << endl;
				break;

			case 1:
				cout << "Enter a word: ";
				getline(cin , word);
				cout << "Enter the position (row col): ";
				getline(cin,position);
				cout << "Enter the direction (0:horizontal, 1:vertical, 2:diagonal): ";
				cin>>direction;
				addWord(word, position, direction);
				break;

			case 2:
				printPuzzle();
				break;

			case 3:
				completePuzzle();
				break;

			default:
				cout << "\n===Invalid Selection, try again===\n" << endl;
				break;
			}

		} while (s != 0);
	}
}
