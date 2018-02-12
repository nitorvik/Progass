// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iomanip>


llist list;
Move m;

int board[8][8];
int cx[] = {-2,-1, 1, 2, 2, 1, -2, -1 };
int cy[] = { 1, 2, 2, 1, -1, -2, -1, -2 };
int movenum = 1;
int backtrack = 0;
int m1;
int m2;

Move first;




/* Initialization of 8x8 board, fill the array with -1 */
void initboard() {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			board[x][y] = -1;
		}
	}
}


/* Output the current board array */
void printboard(int arr[8][8]) {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			cout << std::setw(2) << arr[x][y] << " ";
		}
		cout << endl;
	}
}

void updateboard(int k, int b) {
	board[k][b] = movenum;
	movenum++;
}

//void calcmove(int x, int y, int i) {
//	for (i; i < 8; i++) {
//		int a0 = x + cx[i];
//		int a1 = y + cy[i];
//
//		if (constraints(a0, a1) == false) {
//			updateboard(a0, a1);
//			m.x = a0;
//			m.y = a1;
//			m.index = i;
//			list.push(m);
//			//list.display();
//			backtrack = 0;
//			if (movenum != 65) {
//				return calcmove(m.x, m.y, 0);
//			}
//		}
//	}
//	board[m.x][m.y] = -1;
//	m = list.pop();
//	if (backtrack > 0) {
//		movenum--;
//	}
//	backtrack++;
//	if (movenum != 65) {
//		return calcmove(m.x, m.y, m.index);
//	}
//}


//void goback(int k, int b) {
//	board[k][b] = -1;
//	movenum=movenum-1;
//	list.display();
//	Move m = list.pop();
//	bool cando = calcmove(m.x, m.y, m.index);
//	cout << "prev is " << m.x << " , " << m.y << endl;
//	printboard(board);
//	if (cando) {
//	  return;
//	}
//	else {	
//		
//	return goback(m.x,m.y);
//	}
//}

//void findpath(){
//	bool cando = calcmove(m.x, m.y, 0);
//	if (cando) {
//	return;
//	}
//	else {
//		
//		goback(m.x, m.y);
//	}
//}

//bool onedeg(int x, int y, int xx, int yy)
//{
//	for (int i = 0; i < 8; ++i)
//		if (((x + cx[i]) == xx) && ((y + cy[i]) == yy))
//			return true;
//
//	return false;
//}

bool constraints(int k, int b) {
	if ((k < 0) || (b < 0) || (k > 7) || (b > 7)) 
		return true;
	else 
		return false;
}

bool empty(int k, int b) {
	if ((board[k][b] < 0) && !constraints(k,b)) 
		return true;
	else 
		return false;
}

bool calcmove() {

	int i;

	if (board[m.x][m.y] == 64) 
		return true;


	if (backtrack > 0) 
		i = m.index;
	else
		i = 0;

	for (i; i < 8; ++i) {
		int a0 = m.x + cx[i];
		int a1 = m.y + cy[i];

		if (empty(a0, a1)) {
			board[a0][a1] = board[m.x][m.y] + 1;
			m.x = a0;
			m.y = a1;
			m.index = i;
			list.push(m);
			printboard(board);
			backtrack = 0;
			//if (calcmove(m.x, m.y, 0) == true) {
			//	return true;
			//}
			//else {
			//	board[m.x][m.y] = -1;

			//}
			return false;
		}
	}

	board[m.x][m.y] = -2;
	m = list.pop();
	m.index = m.index + 1;
	//if (backtrack > 0) {
	//	movenum--;
	//	board[m.x][m.y] = -1;
	//}

	backtrack++;
	printboard(board);
	return false;
	//if (movenum < 64) {
	//	return calcmove(m.x, m.y, m.index);
	//}
	//else { return false; }
}


/*Check to see if move is within the constraints of the board*/



int movesavailable(int a, int b) {
	int count = 0;
	for (int i = 0; i < 8; ++i) {
		if (empty(a + cx[i], b+ cy[i]) == true) 
			count++;
	}
	return count;
}

bool heuristic(Move a) {

	int idx = -1;
	int deg = 9;
	int x, y, c;
	int select = rand() % 8;

	if (board[m.x][m.y] > 31) 
		return true;

	for (int i = 0; i < 8; ++i) {
		int k = (select + i) % 8;
		x = m.x + cx[k];
		y = m.y + cy[k];
		if ((empty(x, y) == true) && (c = movesavailable(x,y)) <  9) {
			idx = k;
			deg = c;
		}
	}

	if (idx == -1) {
		return false;
	}

	x = m.x + cx[idx];
	y = m.y + cy[idx];

	board[x][y] = board[m.x][m.y] + 1;
	//printboard(board);

	m.x = x;
	m.y = y;
	list.push(m);

	return true;
}




bool findpath() {
	
	for (int i = 0; i < 31; ++i)
		if (heuristic(m) == false) 
			return false;


	/*if (!onedeg(m.x, m.y, m1, m2)) {
		return false;
	}*/


	return true;

}

int main()
{
	srand(time(0));

	m1 = rand()%8;
	m2 = rand()%8; //random 
	
	m.x = m1;
	m.y = m2;
	m.index = 0;
	list.push(m);
	
		
	initboard();
	board[m1][m2] = 1;
	
	
	while (!findpath()) {
		;
	}

	while (!calcmove()) {
		;
	}

	printboard(board);

	return 0;

}


//list.push(first); //push first node on to stack

//updateboard(m1, m2); //update board
//calcmove(first.x, first.y, 0);

/*while (movenum != 65) {
calcmove(m.x,m.y);
}*/
