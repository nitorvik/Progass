/*This file contains main and the functions necessary to complete the Knight's Tour Problem*/

#include "Header.h"
#include <stdio.h>
#include <iomanip>


llist list;
llist initpos;
Move m;
Move initials;

/*Initialize board, possible x and y moves to iterate through, and variables needed to complete the operation*/
int board[8][8];
int cx[8] = { -2,-1, 1, 2, 2, 1, -2, -1 };
int cy[8] = { 1, 2, 2, 1, -1, -2, -1, -2 };
int backtrack = 0;
int m1;
int m2;
int poppedonce = 0;
int prevmovex = 0, prevmovey = 0;
int posnum = 0;


/* Initialization of 8x8 board.  Iterate through rows and columns to fill the array with -1 in every position*/
void initboard() {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			board[x][y] = -1;
		}
	}
}

/* Output the current board array.  Iterate through the rows and columns to print out each value with a space in between.*/
void printboard(int arr[8][8]) {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			cout << std::setw(2) << arr[x][y] << " ";
		}
		cout << endl;
	}
}

/*Check to see if move is within the constraints of the board*/
bool constraints(int k, int b) {
	if ((k < 0) || (b < 0) || (k > 7) || (b > 7)) //Both moves have to be between 0 and 7
		return true;							  //Return true if there are constraints/the edges of the board are violated
	else
		return false;							  //Return false if no constraints are violated
}

/*Check to see if the next move will be in an available spot.  The available spot will need to have a value of -1 and will need to be on the board.*/
bool empty(int k, int b) {
	if ((board[k][b] < 0) && !constraints(k, b)) //Also checking constraints to assure move is on the board
		return true;
	else
		return false;
}

/*This function takes over when the heuristics are turned off after move 32, so it is responsible for completing moves 33-64.
This function checks if the operation is completed (on move 64), whether or not the list is in the process of backtracking, and
calculates the next available, "safe" move that the Knight should make.  Each move is calculated and checked to assure it is to an
empty spot that is on the board.  If it iterates through all available move and none are valid, it will begin backtracking by
popping the previous value from the linked list and continuing from the index that it left off at for checking moves.*/
bool calcmove() {

	int i; //Initialize the index that will be incremented and stored in the Move structure that is in each node pushed to the list.

	if (board[m.x][m.y] == 64) //Check to see if the operation is complete and the 64th move has been completed
		return true;

	if (backtrack > 0) /*Check to see if the function was previously backtracking or not.  If backtracking took place on the previous iteration,
					   the function needs to pick up at the index the selection process had previously ended at and continue with the next move
					   move selection.*/
		i = m.index + 1;
	else
		i = 0;			// If the function did not backtrack on the previous iteration, the index is set to 0 so it can start with the first move

	for (i; i < 8; i++) {  //Iterate through the moves loaded in the x and y arrays
		int a0 = m.x + cx[i];	//add the moves to the current location the Knight is in
		int a1 = m.y + cy[i];

		if (empty(a0, a1) && (a0 != prevmovex) && (a1 != prevmovey)) { //Check the new moves to see if the spot is available and on the board
			board[a0][a1] = board[m.x][m.y] + 1; //If the move is valid, update the board with the next move number
			if (backtrack > 0) {		//If the function previously backtracked, and it found a new move that is valid, the index needs to be 
				m.index = i;			//reset and the move needs to be pushed back on to the stack to prevent the same moves from being repeated 
				list.push(m);			//after a move was previously involved in the backtracking
			}
			m.x = a0;					//Updated the Move structure with the moves and index
			m.y = a1;
			m.index = i;
			list.push(m);				//Push the moves and index to the list
			backtrack = 0;
			prevmovex = a0;				//Set the new moves as previous moves to prevent a loop
			prevmovey = a1;
			return false;				//Return false to continue looping
		}
	}

	prevmovex = m.x;					//Set the moves as previous moves to prevent a loop
	prevmovey = m.y;
	board[m.x][m.y] = -1;				//Updated board to -1 to make the space available again
	if (backtrack == 0) {				//If it is backtracking for the first time after pushing new values to the list, it will need to pop twice to 
		m = list.pop();					//match the correct moves with the corect space, otherwise, the list will become one move off and the move that 
		m = list.pop();					//the backtracking began on will not be changed.
	}
	else {
		m = list.pop();					//If it was not just pushed, pop only once
	}
	backtrack++;						//keep track of how many times the backtracking has occured
	return false;

}

/*For Warnsdorff's Algorithm heuristics.  The function checks the degree, or how many available moves can be made of the next move, then returns that number.*/
int movesavailable(int a, int b) {
	int count = 0;
	for (int i = 0; i < 8; ++i) {
		if (empty(a + cx[i], b + cy[i]) == true)
			count++;
	}
	return count;
}

/*Contains Warnsdorff's Algorithm.  This function looks at the degree of a given next valid move and decides which move to make based on which currently available move
has the next move that has the lowest degree, or fewest possible moves*/
bool heuristic() {
	int idx = -1;
	int deg = 9;
	int x, y, c;
	int select = rand() % 8;  //randomly select a place in the x and y arrays to begin looking at available moves

	for (int i = 0; i < 8; ++i) {  //Iterate through to check eveery move
		int k = (select + i) % 8;  //mod to ensure every move is checked
		x = m.x + cx[k];			//add new moves to existing position
		y = m.y + cy[k];
		if ((empty(x, y) == true) && (c = movesavailable(x, y)) <  deg) {  //check that a move is valid (on the board and the space is empty)
			idx = k;			//Save the index that the best move is chosen on
			deg = c;			//if the degree of a move's next move is tested and is lower than the previously lowest degree of a different move's next move,
		}						//update the lowest degree.
	}

	if (idx == -1) {			//if index is not updated, restart function
		return false;
	}

	x = m.x + cx[idx];			//create next move by adding the current position to the best move possible
	y = m.y + cy[idx];

	board[x][y] = board[m.x][m.y] + 1; //update board with the next move number

	m.x = x;					//update the structure, push to list
	m.y = y;
	list.push(m);

	return true;
}

/*This function iterates through the heuristics for 32 moves, then turns them off*/
bool findpath() {

	for (int i = 0; i < 31; ++i)
		if (heuristic() == false)
			return false;
	return true;
}

/*Contains user input for the initial positions to be entered by the user.*/
bool initialpositions() {

	int firstpos[2];
	char ans;

	do {
		cout << "Enter Initial X Position" << endl;			//Enter X position to add to list, check if it is numeric and is on the board
		cin >> firstpos[0];
	} while (isalpha(firstpos[0]) || constraints(firstpos[0], 0));

	do {
		cout << "Enter Initial Y Position" << endl;		//Enter y position to add to list, check if it is numeric and is on the board
		cin >> firstpos[1];
	} while (isalpha(firstpos[1]) || constraints(firstpos[1], 0));

	initials.y = firstpos[0];		//Add moves to structure
	initials.x = firstpos[1];
	initials.index = 0;
	initpos.push(initials);		//push to board
	initpos.display();			//display after pushing

	posnum++;					//increment number of initial starting positions in list.

	do {
		cout << "Enter Another Starting Position? (Y/N)" << endl;
		cin >> ans;
	} while (!isalpha(ans));

	if (ans == 'Y') {
		return false;
	}
	else if (ans == 'N') {
		return true;
	}
}

/*Function contains all functions that can be used to delete a node, add a node, or modify a node of the list*/
bool modlist() {

	int input;

	cout << "Make a Selection" << endl;
	cout << " 1. Add A Position" << endl;
	cout << " 2. Delete A Position" << endl;
	cout << " 3. Modify a Position" << endl;
	cout << " 4. Display List" << endl;
	cout << " 5. Run Tour(s)" << endl;

	cin >> input;

	switch (input) {
	case 1:
		initpos.insert_new();
		posnum++;
		return false;
		break;
	case 2:
		initpos.delete_position();
		posnum--;
		return false;
		break;
	case 3:
		initpos.modify();
		return false;
		break;
	case 4:
		initpos.display();
		return false;
		break;
	case 5:
		return true;

	}
}


int main(void)
{
	while (!initialpositions()) {  //Gather initial positions in list
		;
	}

	while (!modlist()) {			//Check to see if uer wants to modify anything
		;
	}

	while (posnum > 0) {			//iterate as long as there are initial moves still in the list

		initials = initpos.pop();		//grab initial starting position from list
		m1 = initials.x;
		m2 = initials.y;

		m.x = m1;				//assign to structure
		m.y = m2;
		m.index = 0;
		list.push(m);			//push first move to list

		initboard();
		board[m1][m2] = 1;     //set first move at initial position


		while (!findpath()) {  //initiate heuristics
			;
		}

		while (!calcmove()) {  //Utilize linked list and backtracking after move 32
			;
		}


		printboard(board);   //print final board with all moves filled in
		cout << endl;

		posnum--;		//decrement o keep track of number of initial moves entered in list
	}
	return 0;

}