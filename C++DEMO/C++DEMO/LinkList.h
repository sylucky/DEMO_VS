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

//�������� Unidirectional linked list
class List
{
public:
	List();
	~List();
	void linsert(int da);//����β������
	void ldelete(int da);
	int lsearch(int da);
	void lgetVal(int po);
	void lsetVal(int da,int val);
	void ldisplay();
private:
	Node *head, *tail;
	int position;
};

