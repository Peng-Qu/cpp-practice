#include "matrix.h"

void horizontalDLL (Element*& head, int index){//ok
	if (head == nullptr){
		head = new Element {nullptr, nullptr, nullptr, nullptr, index};
		head -> left = head;
		head -> right = head;
		return;
	}else{
		Element* tail = head -> left;
		tail -> right = new Element {nullptr, nullptr, tail, head, index};
		head -> left = tail -> right;
	}
}
void connectUpDown (Element* upper, Element* lower){//ok
	if (upper == nullptr || lower == nullptr){
		return;}
	Element* upperHead = upper;

	do{
		upper -> down = lower;
		lower -> up = upper;
		upper = upper -> right;
		lower = lower -> right;
	} while (upperHead != upper);
}
void connectLeftRight (Element* left, Element* right){//ok
	if (left == nullptr || right == nullptr){
		return;}
	Element* rightHead = right;

	do{
		right -> left = left;
		left -> right = right;
		right = right -> down;
		left = left -> down;
	} while(rightHead != right);
}

Matrix::Matrix(int height, int width){//ok
	this->height = height;
	this->width = width;
	for (int i = 0; i < MAX_SIZE; i++){
		rowHeads[i] = nullptr;
		colHeads[i] = nullptr;
	}
	for (int h = 0; h < height; h++){	//create horizontal doubly linked list
		for (int w = 0; w < width; w++){
			horizontalDLL (rowHeads[h], h*width + w + 1);
		}
		if (h > 0){
			connectUpDown (rowHeads[h-1], rowHeads[h]);
		}
	}
	connectUpDown (rowHeads[height-1], rowHeads[0]);	//for connecting the last row with the first row

	Element* current = rowHeads[0];
	for(int col = 0; col < width; col++){
		colHeads[col] = current;
		current = current -> right;
	}
}

bool Matrix::isReverse() const{
	int count = 1;
	for (int row = height-1; row >= 0; row--){
		Element* current = rowHeads[row] -> left;
		for (int col = 0; col < width; col++){
			if ((current->id) != count){return false;}
			count++;
			current = current -> left;
		}
	}
	return true;
}
void invert(Element* cll) {
    if (cll->right == cll){
    	return;
    }
    Element* right = cll->right;
    Element* left = cll->left;
    right->left= left;
    left->right = right;
    invert(right);
    cll->right = left;
    cll->left = right;
    left->left= cll;
    right->right= cll;
}
void Matrix::reverseRow(int row){
	if (row < 0 || row >= height){
		return;
	}
	invert (rowHeads[row]);
	rowHeads[row] = rowHeads[row]->right; //The recursion needs to take an extra shift.

	connectUpDown (rowHeads[(row-1+height)%height], rowHeads[row]);
	connectUpDown (rowHeads[row], rowHeads[(row+1+height)%height]);

	if (row==0){	//special condition when row reversing row 0, update colHeads
		Element* head = rowHeads[0];
		for (int col = 0; col < width; col++){
			colHeads[col] = head;
			head = head -> right;
		}
	}
}
void Matrix::circularShift(Direction dir, int rowcol){
	if (rowcol < 0 ) return;
	if(dir == UP || dir == DOWN){
		if (rowcol >= width) return;
	}
	else{
		if (rowcol >= height) return;
	}
	//Element* newhead;
	switch (dir){	//shift rowhead or colhead
		case UP: colHeads[rowcol] = colHeads[rowcol]->down; break;
		case DOWN: colHeads[rowcol] = colHeads[rowcol]->up; break;
		case LEFT: rowHeads[rowcol] = rowHeads[rowcol]->right; break;
		case RIGHT: rowHeads[rowcol] = rowHeads[rowcol]->left; break;
	}
	switch (dir){
		case UP:
		case DOWN:
			if (width != 1){
				connectLeftRight(colHeads[(rowcol-1+width)%width], colHeads[rowcol]);
				connectLeftRight(colHeads[rowcol], colHeads[(rowcol+1)%width]);
			}
			//colHeads[rowcol] = newhead;
			if (rowcol == 0){
				Element* current = colHeads[0];
				for (int row = 0; row < height; row++){
					rowHeads[row] = current;
					current = current -> down;
				}
			}
			break;
		case LEFT:
		case RIGHT:
			if (height != 1){
				connectUpDown (rowHeads[(rowcol-1+height)%height], rowHeads[rowcol]);
				connectUpDown (rowHeads[rowcol], rowHeads[(rowcol+1)%height]);
			}
			//rowHeads[rowcol] = newhead;
			if (rowcol == 0){
				Element* current = rowHeads[0];
				for (int col = 0; col < width; col++){
					colHeads[col] = current;
					current = current -> right;
				}
			}
			break;
	}
}

Matrix::~Matrix() {
    for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++) {
	    Element* next = rowHeads[i]->right; //it is wrong if delete rowHeads[i] goes first.
	    delete rowHeads[i];
	    rowHeads[i] = next;
	}
}
