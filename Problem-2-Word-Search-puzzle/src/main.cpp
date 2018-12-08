#include "puzzle.h"
using namespace std;

int main(){
	int size, option, dirnum;
	char word[20] = "";
	Position posit;
	WordPuzzle* puzzle = nullptr;
	srand (time(NULL));

	cout << "----- Create Your Word Puzzles -----" << endl;
	cout << "Enter the size of the puzzle:" << endl;
	cin >> size;
	puzzle = new WordPuzzle(size);

	do{
		cout << "Please choose one of the followings:" << endl;
		cout << "0. Quit the program" << endl;
		cout << "1. Add a word" << endl;
		cout << "2. Print the puzzle" << endl;
		cout << "3. Complete the puzzle" << endl;
		cin >> option;

		if (option == 1){
			do{
				cout << "Enter a word:" << endl;
				cin >> word;
				cout << "Enter the position (row col):" << endl;
				cin >> posit.row >> posit.col;
				cout << "Enter the direction (0:horizontal, 1:vertical, 2:diagonal):" << endl;
				cin >> dirnum;
			} while (!(puzzle->add_word(word, posit, static_cast<Direction>(dirnum))));
		}
		else if (option == 2){
			puzzle->print();
		}
		else if (option == 3){
			puzzle->complete_puzzle();
		}
		else{
			cout << "Invalid option, please enter again:" << endl;
		}
	} while (option!=0);

	return 0;
}
