#pragma once

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <ostream>

using std::cout;
using std::endl;
using std::cin;
using std::aligned_storage_t;

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
		}
	}

	Move pop() {

		if (start == NULL) {
			throw std::runtime_error("The list is empty");
		}
		else {
			Move data = start->info;
			struct node* temp = new node;
			temp = start;
			start = start->next;
			delete temp;
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
			cout << "List is Empty" << endl;
			return;
		}
		temp = start;
		cout << "List contains: " << endl;
		while (temp != NULL)
		{
			cout << temp->info.y <<" , " << temp->info.x << endl;
			temp = temp->next;
		}
	}

	void delete_position()
	{
		int pos;
		int i;
		int x = 0;

		if (start == NULL)
		{
			cout << "List is empty" << endl;
			return;
		}

		cout << "Enter Position to Delete: ";

		cin >> pos;

		struct node *p, *ptr = nullptr;

		p = start;

		if (pos == 1)
		{
			start = p->next;
		}
		else
		{
			while (p != NULL)
			{
				p = p->next;
				x++;
			}
			if (pos > 0 && pos <= x)
			{

				p = start;

				for (i = 1; i < pos; i++)
				{
					ptr = p;
					p = p->next;
				}
				ptr->next = p->next;
			}
			else
			{
				cout << "Position out of range" << endl;
			}
			delete(p);
			cout << "Element Deleted" << endl;
		}

	}

	void insert_new()

	{
		Move y;
		int pos;
		int counter = 0;
		int i;
		int val;

		cout << "Enter the new node X value: ";

		cin >> val;
		y.y = val;

		cout << "Enter the new node Y value: ";

		cin >> val;
		y.x = val;
		y.index = 0;

		struct node *temp, *p, *ptr = nullptr;

		temp = newnode(y);

		cout << "Enter Position to Insert Node At: ";

		cin >> pos;

		p = start;
		while (p != NULL)
		{
			p = p->next;
			counter++;
		}
		if (pos == 1)
		{
			if (start == NULL)
			{
				start = temp;
				start->next = NULL;
			}
			else
			{
				ptr = start;
				start = temp;
				start->next = ptr;
			}
		}
		else if (pos > 1 && pos <= counter)
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

	void modify()

	{
		int value, pos, i;
		struct node *p, *ptr;

		if (start == NULL)

		{
			cout << "List is empty" << endl;
			return;
		}

		cout << "Enter the node postion to be updated: ";

		cin >> pos;

		cout << "Enter the new X value: ";

		cin >> value;

		p = start;

		if (pos == 1)
		{
			start->info.y = value;
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

		if (pos == 1)
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
