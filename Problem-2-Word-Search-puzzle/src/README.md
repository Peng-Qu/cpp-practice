### main.cpp

Main body of the program. Keeps the game running unless player chooses option 0 "Quit the program" by using do-while iteration.
When player enter the size of the puzzle, class constructor is called to construct a triangular puzzle with empty entries '_'.

### puzzle.h

A header file which contains the definition of struct 'Position' and class 'WordPuzzle'. Definition of class function is defined in
function.cpp

### function.cpp

Class functions are defined here, including constructor, destructor (dynamic-2D array is used for the puzzle), accessor (print()
for printing the puzzle), mutator (add_word to add words into the puzzle and complete_puzzle to complete empty entries with random
characters)
