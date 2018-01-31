#include "stdafx.h"
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "LinkedList.h"
using std::cin;
using std::cout;
using std::endl;

int board[8][8]; /*8x8 int array to represent the board*/

int cx[] = { -2, -1, 1, 2, 2, 1, -2, -1};
int cy[] = { 1,2,2,1,-1,-2,-1,-2 };

List<int> list1;
Stack<int> stack1;
ListItr<int> listitr1;

/*Check to see if move is within the constraints of the board*/
bool constraints(int arr[]) {
	if (((arr[0] < 0 | arr[1]) < 0) | ((arr[0] > 8 | arr[1]) > 8)) {
		return true;
	}
	else {
		return false;
	}
}

/* Initialization of 8x8 board, fill the array with -1 */
void initboard() {
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			board[x][y] = -1;
		}
	}
}


/* Output the current board array */
void printboard(int arr[8][8]) {
	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			cout << std::setw(2) << arr[x][y] << " ";
			}
			cout << endl;
	}
}


void push(int x) {
	list1.insert(x, list1.zeroth());
}

int pop() {
	int x = list1.first().retrieve();
	list1.remove(x);
	return x;
}


int main()
{

initboard();


cout << "this is working" << endl;

int v[] = { 5, 9 };
int init[] = { rand() % 9, rand() % 9 };

board[init[0]][init[1]] = 1;

printboard(board);

if (constraints(v)) {
	cout << "outside of contraints" << endl;
}




}



// do you want to write a stack class?
// first write tests!! (i wrote a couple)
//
// if you want to make a push method, just have it call list.insert(x, list.zeroth())
//
// if you want to write a pop method, just have it do ... this....
// int x = list.first().retrieve();
// list.remove(x);
// this will return the first element, and then remove that node from the list

// don't get thrown off by the <Object> stuff, templates are just a bunch of pre-compile things to make it easier to code classes that take generic types
// so, whenever you see <Object> say in your mind "of Object"
// if you do this
// List<int> myList;
// you are creating a List of ints called myList




