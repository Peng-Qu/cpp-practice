#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

using namespace std;

const int MAX_SIZE = 8;
enum Direction {UP, DOWN, LEFT, RIGHT};

/**
 * Representing an element in a matrix.
 *
 */
struct Element {
    Element* up;    // To link to the element on the same col in the above row. If this element is in the top row (Row-0), it links to the elements on Row-(m-1)
    Element* down;  // Similar to up but it is to link to the element in the row below.
    Element* left;  // To link to the element on the left.
    Element* right; // To link to the element on the right.
    const int id;   // We intentionally to have it as a const so you need to handle the links instead of changing the value.
};

class Matrix {
    private:
	int width;      // The width of the matrix
	int height;		// The height of the matrix
	Element* rowHeads[MAX_SIZE];   // Pointer arrays. Please refer to the PA3 webpage
	Element* colHeads[MAX_SIZE];
    public:

	Matrix(int height, int width);

	~Matrix();

	void reverseRow(int);

	void circularShift(Direction, int);

	bool isReverse() const;

	void print() const;

	void debug() const;

};



#endif
