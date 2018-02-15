#pragma once

#include <stdexcept>
#include <iostream>
#ifndef HEADER_H
#define HEADER_H
#include<cstdlib>


using std::cout;
using std::endl;
using std::cin;

/*The structure that will contain the index for checking for a next move and the x and y positions for all moves pushed to the list*/
struct Move {
	int x;
	int y;
	int index;
};

/*The node structure that is used to hold the information (a Move struct) and a pointer to the next node*/
struct node
{
public:
	Move info;
	struct node *next;
	node() : next(NULL) {};
};

/*class defining the Linked List*/
class llist {

	struct node *start; /*pointer to the top*/


public:

	llist() : start(NULL) {}; /*Set to NULL*/

	/*List function to push the required information to the list*/
	void push(Move &coords) {  
		struct node *p = new node; //create a node to use

		p = newnode(coords);  //grab information to be pushed
		if (start == NULL) {	
			start = p;		//if it's the first node, pass the required info and set the pointer to NULL	
			start->next = NULL;

		}
		else {
			p->next = start; //If not the first node, pass the previous address and required info
			start = p;
		}
	}

	Move pop() {

		if (start == NULL) {
			throw std::runtime_error("The list is empty"); //nothing to return, so throw runtime error, could also try catch here
		}
		else {
			Move data = start->info;  //grab the required location and index information that needs to be returned 
			struct node* temp = new node;  //create new node
			temp = start;				//grab the current address
			start = start->next;		//reassign to the next node's address
			delete temp;				//free the memory
			return data;				//return required info
		}
	}

	/*Function to create a new node when needed, is passed the Move to be pushed(utilizes reference of the Move) and returns a new node*/
	node *newnode(Move &value) {
		struct node *temp = new(struct node);
		temp->info = value;
		temp->next = NULL;
		return temp;
	}

	/*A function for displaying the List and its current contents*/
	void display()
	{
		struct node *temp;
		if (start == NULL) //Check for empty list
		{
			cout << "List is Empty" << endl;
			return;
		}
		temp = start;  //grab node
		cout << "List contains: " << endl;
		while (temp != NULL)  //return the location information in each node as ordered pair, move to the next node in the list
		{
			cout << temp->info.y << " , " << temp->info.x << endl;
			temp = temp->next;
		}
	}

	/*Function to delete a node at a given position*/
	void delete_position()
	{
		int pos;
		int i;
		int x = 0;

		if (start == NULL)//check for empty list
		{
			cout << "List is empty" << endl;
			return;
		}

		cout << "Enter Position to Delete: ";  //Prompt User Input
		cin >> pos;

		struct node *p, *ptr = NULL;

		p = start;

		if (pos == 1) //Check for the position by iterating until the position is matched
		{
			start = p->next;
		}
		else
		{
			while (p != NULL)//find the start of the list
			{
				p = p->next;
				x++;
			}
			if (pos > 0 && pos <= x)
			{

				p = start;

				for (i = 1; i < pos; i++) //Move to the entered position. Passes location pointer to reassign so the node being deleted is no longer referenced
				{
					ptr = p;
					p = p->next;
				}
				ptr->next = p->next;
			}
			else
			{
				cout << "Out of range" << endl; //Check to see if position entered is valid
			}
			delete(p);
			cout << "Deleted" << endl;
		}

	}

	/*Function for inserting a new node somewhere in the list*/
	void insert_new()
	{
		Move y;
		int pos;
		int counter = 0;
		int i;
		int val;

		cout << "Enter the new node X value: ";  //similar to initial starting point entry
		cin >> val;
		y.y = val;

		cout << "Enter the new node Y value: ";
		cin >> val;
		y.x = val;
		y.index = 0;

		struct node *temp, *p, *ptr = NULL;

		temp = newnode(y); //create new node

		cout << "Enter Position to Insert Node At: ";

		cin >> pos;

		p = start;
		while (p != NULL) //find beginning
		{
			p = p->next;
			counter++;
		}
		if (pos == 1)
		{
			if (start == NULL)
			{
				start = temp;  //similar to pushing, inserting node
				start->next = NULL;
			}
			else
			{
				ptr = start;
				start = temp;
				start->next = ptr;
			}
		}
		else if (pos > 1 && pos <= counter) //find the position entered if it is not 1, insert the new node, update address pointers
		{
			p = start;
			for (i = 1; i < pos; i++)
			{
				ptr = p;
				p = p->next;
			}
			ptr->next = temp;
			temp->next = p;
		}
		else
		{
			cout << "Out of range" << endl;
		}
	}

	/*function to modify an entry in the list in place - enables user to overwrite starting positions and enter new ones at the same time*/
	void modify()
	{
		int value, pos, i;
		struct node *p;

		if (start == NULL) //check for empty

		{
			cout << "List is empty" << endl;
			return;
		}

		cout << "Enter the node postion to be updated: ";  //prompt user input
		cin >> pos;

		cout << "Enter the new X value: ";
		cin >> value;

		p = start;

		if (pos == 1)
		{
			start->info.y = value;  //store new x value
		}
		else
		{
			for (i = 0; i < pos - 1; i++)
			{
				if (p == NULL)
				{
					cout << "Invalid Position";
					return;
				}
				p = p->next;
			}
			p->info.y = value;
		}

		cout << "Enter the new Y value: ";
		cin >> value;

		p = start;

		if (pos == 1)  //store new y value
		{
			start->info.x = value;
		}
		else
		{
			for (i = 0; i < pos - 1; i++)
			{
				if (p == NULL)
				{
					cout << "Invalid Position";
					return;
				}
				p = p->next;
			}
			p->info.x = value;
		}
	}
};
#endif
