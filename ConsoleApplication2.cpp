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
int cx[] = { -2, -1, 1, 2, 2, 1, -2, -1 };
int cy[] = { 1, 2, 2, 1, -1, -2, -1, -2 };
int movenum = 1;



/*Check to see if move is within the constraints of the board*/
bool constraints(int k, int b) {
	if ((k < 0) | (b < 0) | (k > 7) | (b > 7) | (board[k][b] != -1)) {
		return true;
	}
	else {
		return false;
	}
}

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

bool calcmove(int x, int y, int i) {
	for (i; i < 9; i++) {
		int a0 = x + cx[i];
		int a1 = y + cy[i];
		if (constraints(a0, a1) == false) {
			updateboard(a0, a1);
			m.x = a0;
			m.y = a1;
			m.index = i;
			list.push(m);
			//list.display();
			return true;
		}
	}
	return false;
}


void goback(int k, int b) {
	board[k][b] = 69;
	list.display();
	Move prev = list.pop();
	bool cando = calcmove(prev.x, prev.y, prev.index);
	cout << "prev is " << prev.x << " , " << prev.y << endl;
	//if (cando) {
	//    list.push(prev);
	//}
	//else {
	////goback(prev.x,prev.y);
	//}
}

bool findpath(){
	bool cando = calcmove(m.x, m.y, 0);
	if (cando) {
	return false;
	}
	else {
		goback(m.x, m.y);
		return false;
	}
	return true;
}


/* Main :contains menu*/

int main()
{
	int m1 = 1;
	int m2 = 2; //random 
	
	m.x = m1;
	m.y = m2;
	m.index = 0;
	list.push(m); //push first node on to stack
		
	initboard();
	updateboard(m1, m2); //update board
	

	while (!findpath()) {
		;
	}


	printboard(board);

}

////int * p = std::find(board[0], board[63], -1);
//while (p != board[63]) {
//}
