README

Programming Assignment #1 - Knight's Tour Using Warnsdorff's Heuristic & Linked List
CSCI 362

************************************************
Description
************************************************
A Knight's Tour refers to the sequence of moves necessary for a knight to make to touch every square on a 
chess board (typically 8x8 spaces) exactly once. There are a number of ways to find a Knight's Tour with 
a program. This project will utilize Warnsdorff's Algorithm and a Linked List to find it. The program is 
to first apply Warnsdorff's Algorithm and find the first 32 moves, then switch to a Linked List implementation 
to utilize backtracking to find the last 32 moves. Once the Knight has touched every square, the tour is 
completed and the moves must be returned as an 8x8 board with each position marked with the move number 
at which the knight visited each space. 

*************************************************
Included Files:
*************************************************
Header.h
LinkedList.cpp

*************************************************
Operation
*************************************************
TO RUN: g++ LinkedList.cpp -o LinkedList
	./LinkedList
	
i. User Input
	The User Input at the beginning of the program requires users to enter x and y values 
	separately. This simplified the process of adding user input by only requiring the program
	to handle one int at a time so I didn't need to handle and ordered pair as a string.  Each pair
	of x and y values is used as the starting position for the Knight for one iteration of the 
	tour.  Because each ordered pair is pushed to a Linked List, the program will continue to 
	rerun the tour with the next ordered pair in the list until the list is empty.  x and y values 
	must be entered each as a single integer from 0-7.
	User Input continues with the program requiring the User to select whether they want to modify 
	the list of initial positions in some way or continue and run the tour(s).

ii. Heuristic
	The Program will run a heuristic known as Warnsdorff's Algorithm. It is used to reduce the running
	time of the program because, using backtracking alone, the worst case number of combinations to
	check is 8^64. From Wikipedia:  The knight is moved so that it always proceeds to the square from 
	which the knight will have the fewest onward moves. This should result in the correct sequence of
	moves being selected to solve the tour. The heuristic is turned off after 32 moves so a Linked List
	can be implemented to solve the rest of the tour. 

iii. Linked List with Backtracking
	After the heuristic is turned off, the continued operation of the program is taken over by Linked List 
	stack implementation. The Linked List was required to store the moves made so if the knight ended up 
	in a position that had no valid moves to continue on to, the previous move or moves could be popped
	from the List and a new move could be made. To do this, each successful move was pushed to the List,
	then popped when moves ran out until all 64 moves had been made. The x and y  coordinates of each move, 
	along with an index that dictated which move had been tested last for that position, were pushed to
	the stack as each succeddful move was made. If backtracking occured, the x and y for the previous 
	position could be loaded and the next possible move could be tried. Getting the backtracking to work
	properly was the most challenging part of this project. Lots of special cases came up when trying to 
	pop and then move forward again, so those special cases had to be correctly addressed. The most 
	difficult error to identify was the necessity to push a backtracked move back to the stack if it found
	a new move to make with a different index.  This was solved by adding a condition that is backtracking 
	had occured, but a new successful move had been identified from the same position, the position gets 
	pushed back to the List with the new, incremented index. Each node of the Linked List was created with 
	a pointer to the next node and a 'Move' structure that contained 3 variables: x, y, and index. The 
	structure variables were updated to contain the current position on the board and the index of the move 
	selected, then the move was added to a new node and pushed to the List. This made it easier to keep 
	track of the position information.

iv. Termination
	The program terminates after each initial positions entered in the initial Linked List created in the 
	User Input stage has been used and the completed boards, with all moves filled in sequentially, are returned.