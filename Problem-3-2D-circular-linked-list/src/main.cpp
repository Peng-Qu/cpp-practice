#include "matrix.h"

int main() {

    {
	cout << "Try a row matrix" << endl <<
	    "=======================" << endl;
	Matrix rowMatrix(1, 3);
	rowMatrix.debug();
    }
    cout << "The row matrix is destructed" << endl;

    {
	cout << "Try a column matrix" << endl <<
	    "=======================" << endl;
	Matrix colMatrix(5, 1);
	colMatrix.debug();
    }
    cout << "The column matrix is destructed" << endl;

    {
	cout << "Test on a 3-by-2 matrix" << endl <<
	    "=======================" << endl;
	Matrix m32(3, 2);
	m32.debug();
    }
    cout << "The 3-by-2 matrix is destructed" << endl;

    {
	cout << endl <<
	    "=======================" << endl <<
	    "Test on a m-by-n matrix" << endl <<
	    "=======================" << endl;
	int m, n;
	do {
	    cout << "Enter m and n" << endl;

	    cin >> m;
	    cin >> n;
	} while (m < 1 || n < 1 || m > MAX_SIZE || n > MAX_SIZE);

	Matrix d(m, n);
	d.print();


	char input1, input2;
	do {
	    cout << "Choose the following operation:" << endl <<
		"1) Up Circular Shift" << endl <<
		"2) Down Circular Shift" << endl <<
		"3) Left Circular Shift" << endl <<
		"4) Right Circular Shift" << endl <<
		"5) Reverse Row." << endl;
	    cin >> input1;
	    cin.ignore();
	    cout << "Enter the row/col to perform. Note. User is assumed rational enough to enter a valid row/col. " <<
		"We will not test on invalid row/col during the grading exercise" << endl;
	    cin >> input2;
	    cin.ignore();
	    if (input1 >= '1' && input1 <= '4' )
		d.circularShift( static_cast<Direction>(input1 - '1'), input2 - '0');
	    if (input1 == '5')
		d.reverseRow(input2 - '0');
	    d.print();
	} while (!d.isReverse());
    }
    cout << "All objects have been destructed. Note: seeing this line does not mean you are memory-leak free. " << endl
	<< "This only means your destructor did not crash." << endl;
}
