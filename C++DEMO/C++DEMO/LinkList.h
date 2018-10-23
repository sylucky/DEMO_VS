#pragma once
#include <iostream>
class Node
{
public:
	Node(int d);
	Node();
	~Node();
	int data;
	Node *next;
};

//单向链表 Unidirectional linked list
class List
{
public:
	List();
	~List();
	void linsert(int da);//链表尾部插入
	void ldelete(int da);
	int lsearch(int da);
	void lgetVal(int po);
	void lsetVal(int da,int val);
	void ldisplay();
private:
	Node *head, *tail;
	int position;
};

