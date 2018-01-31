#include "stdafx.h"
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iomanip>


// you don't need this line, if you'll look at LinkedList.h, you'll see that Source.cpp is included into the header..
// kind of a kludgy way of doing it, but when defining templates, you need to put all the function definitions in the header file
// which this does by including the Source.cpp
#include "LinkedList.h"


// NEVER use a namespace unless you are in the library that the namespace is local to, you're just trying to save yourself
// some typing and you are paying for it with lack of readability and traceability
// super big pet peeve of mine..
// using namespace std;

int board[8][8]; /*8x8 int array to represent the board*/

// don't get thrown off by the <Object> stuff, templates are just a bunch of pre-compile things to make it easier to code classes that take generic types
// so, whenever you see <Object> say in your mind "of Object"
// if you do this
// List<int> myList;
// you are creating a List of ints called myList

//you can't create this twice, it's already in the header file.
///* Construct the list. */
//template <class Object>
//List<Object>::List()
//{
//// where is the ListNode class defiend?
//
//}


/* Copy constructor. */
template <class Object>
List<Object>::List(const List<Object> & rhs)
{
header = new ListNode<Object>;
// this calls the assignment operator defined down below
*this = rhs;
}
/* Destructor. */
template <class Object>
List<Object>::~List()
{
makeEmpty();
delete header;
}

/* Test if the list is logically empty. Return true if empty, false, otherwise.*/
template <class Object>
bool List<Object>::isEmpty() const
{
return header->next == NULL;
}
/* Make the list logically empty. */
template <class Object>
void List<Object>::makeEmpty()
{
while (!isEmpty())
remove(first().retrieve());
}
/* Return an iterator representing the header node. */
template <class Object>
ListItr<Object> List<Object>::zeroth() const
{
return ListItr<Object>(header);
}
/* Return an iterator representing the first node in the list.
This operation is valid for empty lists. */
template <class Object>
ListItr<Object> List<Object>::first() const
{
return ListItr<Object>(header->next);
}

/*Insert item x after p. */
template <class Object>
void List<Object>::insert(const Object & x, const ListItr<Object>& p)
{
if (p.current != NULL)
p.current->next = new ListNode<Object>(x, p.current->next);
}
/* Return iterator corresponding to the first node containing an
item x. Iterator isPastEnd if item is not found. */
template <class Object>
ListItr<Object> List<Object>::find(const Object & x) const {
/* 1*/
ListNode<Object> *itr = header->next;
/* 2*/
while (itr != NULL && itr->element != x)
/* 3*/
itr = itr->next;
/* 4*/
return ListItr<Object>(itr);
}
/* Return iterator prior to the first node containing an item x. */
template <class Object>
ListItr<Object> List<Object>::findPrevious(const Object & x) const
{
/* 1*/
ListNode<Object> *itr = header;
/* 2*/
while (itr->next != NULL && itr->next->element != x)
/* 3*/
itr = itr->next;
/* 4*/
return ListItr<Object>(itr);
}

/* Remove the first occurrence of an item x. */
template <class Object>
void List<Object>::remove(const Object & x)
{
ListItr<Object> p = findPrevious(x);
if (p.current->next != NULL)
{
ListNode<Object> *oldNode = p.current->next;
p.current->next = p.current->next->next;
// Bypass deleted node
delete oldNode;
}
}
/* Deep copy of linked lists.*/
template <class Object>
const List<Object>&List<Object>::operator=(const List<Object> & rhs)
{
if (this != &rhs)
{
makeEmpty();
ListItr<Object> ritr = rhs.first();
ListItr<Object> itr = zeroth();
for (; !ritr.isPastEnd(); ritr.advance(), itr.advance())
insert(ritr.retrieve(), itr);
}
return *this;
}



#if 0
// THIS IS ALL FINEish, but you need to focus on accomplishing small specific goals
// so, i've written tests to verify that the List algorithm works, now we need to focus on what we are trying to do with this thing

// don't reimplement the List class and all that, we've verified the algorithm above works fine enough
struct node
{
int data;
node *next;
};

struct node *head = NULL, *tail = NULL, *n = NULL;

class list {
node * head, *tail;
public:
list() {
head = NULL;
tail = NULL;
}

void newnode(int x) {
node *val = new node;
val->data = x;
val->next = NULL;
if (head == NULL) {
head = val = tail;
val = NULL;
}



// don't do this
void push(int x) {
n = new node;
n->data = x;
n->next = NULL;

if (head == NULL) {
head = n;
n = NULL;
}
else {
tail->next = n;
tail = n;
}
}

// this is fine
/* Initialization of 8x8 board, fill the array with -1 */
void initboard() {
for (int x = 0; x < 9; x++) {
for (int y = 0; y < 9; y++) {
board[x][y] = -1;
}
}
}

// i cleaned this up a bit
/* Output the current board array */
void printboard(int arr[8][8]) {
for (int x = 0; x < 9; x++) {
for (int y = 0; y < 9; y++) {
std::cout << std::setw(2) << arr[x][y] << " ";
}
std::cout << std::endl;
}
}

// user inputs? yuck
//void initcond() {
//
// int xpos;
// int ypos;
//
// while(1){
// cout << "Enter X Position" << endl;
// cin >> xpos;
// if (xpos > 0 && xpos <= 8) {
// break;
// }
// else {
// cout << "Enter X Position" << endl;
// }
//
// while (1) {
// cout << "Enter Y Position" << endl;
// cin >> ypos;
// if (ypos > 0 && ypos <= 8) {
// break;
// }
// else {
// cout << "Enter Y Position" << endl;
// }
//
// }
//}
#endif
// not yet, write tests first, then verify stuff
int main()
{
/*initboard();
printboard(board);*/

std::cout << "this is working" << std::endl;



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


template <class Object>
class Stack : public List<Object> {
public:
void push(Object o) { this->insert(o, this->zeroth()); }
Object pop() { Object o = this->first().retrieve(); this->remove(o); return o; }
};

