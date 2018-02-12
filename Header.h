#pragma once

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <ostream>

using std::cout;
using std::endl;
using namespace std;


struct Move {
	int x;
	int y;
	uint32_t index;
};


struct node
{
public:
	Move info;
	struct node *next;
	node() : next(nullptr) {};
};


class llist {

	struct node *start;
	
	
public:

	llist() : start(nullptr) {};

	void push(Move &coords) {
		struct node *p = new node;

		p = newnode(coords);
		if (start == NULL) {
			start = p;
			start->next = NULL;
		}
		else {
			p->next = start;
			start = p;
			cout << "pushed" << endl;
		}
	}

	Move pop() {

		if (start == NULL) {
			throw std::runtime_error("The list is empty");
		}
		else {
			Move data = start->info;
			struct node *temp = new node;
			temp = start;
			start = start->next;
			delete temp;
			cout << "pop successful" << endl;
			return data;
		}
	}
	
	node *newnode(Move &value) {
		struct node *temp = new(struct node);
			temp->info = value;
			temp->next = NULL;
			return temp;
	}

	void display()
	
	{
		struct node *temp;
		if (start == NULL)
		{
			cout << "The List is Empty" << endl;
			return;
		}
		temp = start;
		cout << "Elements of list are: " << endl;
		while (temp != NULL)
		{

			cout << temp->info.x << "->";
			temp = temp->next;
		}
	
		cout << "empty" << endl;
	}
};




/*Creating Node*/

//node *single_llist::create_node(int value[])
//
//{
//
//	struct node *temp, *s;
//
//	temp = new(struct node);
//
//	if (temp == NULL)
//
//	{
//
//		return 0;
//
//	}
//
//	else
//
//	{
//
//		temp->info = value;
//
//		temp->next = NULL;
//
//		return temp;
//
//	}
//
//}



/*Inserting element in beginning*/

//void single_llist::insert_begin()
//
//{
//
//	int value[] = { 1,2 };
//
//	struct node *temp, *p;
//
//	temp = create_node(value);
//
//	if (start == NULL)
//
//	{
//		start = temp;
//		start->next = NULL;
//	}
//
//	else
//
//	{
//		p = start;
//		start = temp;
//		start->next = p;
//	}
//
//	cout << "Element Inserted at beginning" << endl;
//
//}


/*Insertion of node at a given position*/

//void single_llist::insert_pos()
//
//{
//
//	int value, pos, counter = 0;
//
//	cout << "Enter the value to be inserted: ";
//
//	cin >> value;
//
//	struct node *temp, *s, *ptr;
//
//	temp = create_node(value);
//
//	cout << "Enter the postion at which node to be inserted: ";
//
//	cin >> pos;
//
//	int i;
//
//	s = start;
//
//	while (s != NULL)
//
//	{
//
//		s = s->next;
//
//		counter++;
//
//	}
//
//	if (pos == 1)
//
//	{
//
//		if (start == NULL)
//
//		{
//
//			start = temp;
//
//			start->next = NULL;
//
//		}
//
//		else
//
//		{
//
//			ptr = start;
//
//			start = temp;
//
//			start->next = ptr;
//
//		}
//
//	}
//
//	else if (pos > 1 && pos <= counter)
//
//	{
//
//		s = start;
//
//		for (i = 1; i < pos; i++)
//
//		{
//
//			ptr = s;
//
//			s = s->next;
//
//		}
//
//		ptr->next = temp;
//
//		temp->next = s;
//
//	}
//
//	else
//
//	{
//
//		cout << "Positon out of range" << endl;
//
//	}
//
//}



/*Sorting Link List*/

//void single_llist::sort()
//
//{
//
//	struct node *ptr, *s;
//
//	int value;
//
//	if (start == NULL)
//
//	{
//
//		cout << "The List is empty" << endl;
//
//		return;
//
//	}
//
//	ptr = start;
//
//	while (ptr != NULL)
//
//	{
//
//		for (s = ptr->next; s != NULL; s = s->next)
//
//		{
//
//			if (ptr->info > s->info)
//
//			{
//
//				value = ptr->info;
//
//				ptr->info = s->info;
//
//				s->info = value;
//
//			}
//
//		}
//
//		ptr = ptr->next;
//
//	}
//
//}



/*Delete element at a given position*/

//void single_llist::delete_pos()
//
//{
//
//	int pos, i, counter = 0;
//
//	if (start == NULL)
//
//	{
//
//		cout << "List is empty" << endl;
//
//		return;
//
//	}
//
//	cout << "Enter the position of value to be deleted: ";
//
//	cin >> pos;
//
//	struct node *s, *ptr;
//
//	s = start;
//
//	if (pos == 1)
//
//	{
//
//		start = s->next;
//
//	}
//
//	else
//
//	{
//
//		while (s != NULL)
//
//		{
//
//			s = s->next;
//
//			counter++;
//
//		}
//
//		if (pos > 0 && pos <= counter)
//
//		{
//
//			s = start;
//
//			for (i = 1; i < pos; i++)
//
//			{
//
//				ptr = s;
//
//				s = s->next;
//
//			}
//
//			ptr->next = s->next;
//
//		}
//
//		else
//
//		{
//
//			cout << "Position out of range" << endl;
//
//		}
//
//		free(s);
//
//		cout << "Element Deleted" << endl;
//
//	}
//
//}
//
//
//
///*Update a given Node*/
//
//void single_llist::update()
//
//{
//
//	int value, pos, i;
//
//	if (start == NULL)
//
//	{
//
//		cout << "List is empty" << endl;
//
//		return;
//
//	}
//
//	cout << "Enter the node postion to be updated: ";
//
//	cin >> pos;
//
//	cout << "Enter the new value: ";
//
//	cin >> value;
//
//	struct node *s, *ptr;
//
//	s = start;
//
//	if (pos == 1)
//
//	{
//
//		start->info = value;
//
//	}
//
//	else
//
//	{
//
//		for (i = 0; i < pos - 1; i++)
//
//		{
//
//			if (s == NULL)
//
//			{
//
//				cout << "There are less than " << pos << " elements";
//
//				return;
//
//			}
//
//			s = s->next;
//
//		}
//
//		s->info = value;
//
//	}
//
//	cout << "Node Updated" << endl;
//
//}
//
//
//
///*Searching an element*/
//
//void single_llist::search()
//
//{
//
//	int value, pos = 0;
//
//	bool flag = false;
//
//	if (start == NULL)
//
//	{
//
//		cout << "List is empty" << endl;
//
//		return;
//
//	}
//
//	cout << "Enter the value to be searched: ";
//
//	cin >> value;
//
//	struct node *s;
//
//	s = start;
//
//	while (s != NULL)
//
//	{
//
//		pos++;
//
//		if (s->info == value)
//
//		{
//
//			flag = true;
//
//			cout << "Element " << value << " is found at position " << pos << endl;
//
//		}
//
//		s = s->next;
//
//	}
//
//	if (!flag)
//
//		cout << "Element " << value << " not found in the list" << endl;
//
//}
//
//
//
///*Reverse Link List*/
//
//void single_llist::reverse()
//
//{
//
//	struct node *ptr1, *ptr2, *ptr3;
//
//	if (start == NULL)
//
//	{
//
//		cout << "List is empty" << endl;
//
//		return;
//
//	}
//
//	if (start->next == NULL)
//
//	{
//
//		return;
//
//	}
//
//	ptr1 = start;
//
//	ptr2 = ptr1->next;
//
//	ptr3 = ptr2->next;
//
//	ptr1->next = NULL;
//
//	ptr2->next = ptr1;
//
//	while (ptr3 != NULL)
//
//	{
//
//		ptr1 = ptr2;
//
//		ptr2 = ptr3;
//
//		ptr3 = ptr3->next;
//
//		ptr2->next = ptr1;
//
//	}
//
//	start = ptr2;
//
//}
//
//
//
///*Display Elements of a link list*/
//
//void display()
//
//{
//
//	struct node *temp;
//
//	if (start == NULL)
//
//	{
//
//		cout << "The List is Empty" << endl;
//
//		return;
//
//	}
//
//	temp = start;
//
//	cout << "Elements of list are: " << endl;
//
//	while (temp != NULL)
//
//	{
//
//		cout << temp->info << "->";
//
//		temp = temp->next;
//
//	}
//
//	cout << "NULL" << endl;
//
//}