#ifndef PCH_H
#define PCH_H

using namespace std;
namespace PCH{
	class PuzzleApp {

	private:
		int puzzleSize;
		string board;

		//PuzzleApp 
		int menu();
		void addWord(string word, string position, const int direction);
		void printPuzzle();
		void completePuzzle();


	public:

		//Public member function (method)
		PuzzleApp(const int puzzleSize);
		~PuzzleApp(void);

		void run();
	};
}
#endif //PCH_H
