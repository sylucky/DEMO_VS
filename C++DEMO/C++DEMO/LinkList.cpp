#include "LinkList.h"

#include <stddef.h>

using namespace std;

Node::Node(int d)
{
	this->data = d;
	this->next = NULL;
}

Node::Node()
{
	data = 0;
	next = NULL;
}

Node::~Node()
{
	next = NULL;
}

List::List()
{
	this->head = NULL;
	position = 0;
	(*this).tail = NULL;//another usage
}

List::~List()
{
	delete head;
	delete tail;
}

void List::linsert(int da)
{
	if (head == NULL)//insert data first
	{
		head = new Node();
		tail = new Node(da);
		head->next = tail;
	}
	else
	{
		Node *inode = new Node(da);
		tail->next = inode;
		tail = inode;
	}
}

void List::ldelete(int da)
{
	Node *p;
	p = head;
	if (head == NULL)
	{
		cout << "LinkList is empty!" << endl;
		return;
	}
	//±éÀúÁ´±í
	while (p != tail && p->next->data != da)
	{
		p = p->next;
	}

	if (p->next->data != da)
	{
		cout << "not found the node!" << endl;
		return;
	}

	if (p->next == tail)//delete tail node
	{
		tail = p;
		tail->next = NULL;
	}
	else//delete other node
	{
		p->next = p->next->next;
	}
}

int List::lsearch(int da)
{
	Node *p = head;
	while (p != NULL && p->data != da)
	{
		p=p->next;
	}

	if (p->data != da)
	{
		cout << "not found the node!" << endl;
		return -1;
	}
	else
	{
		cout << "found the node:" << da << endl;
		return da;
	}

	return -1;
}

void List::lgetVal(int da)
{
	Node *p = head;
	while (p != NULL && p->data != da)
	{
		p = p->next;
	}

	if (p==NULL || p->data != da)
	{
		cout << "not found the node!" << endl;
		return ;
	}
	else
	{
		cout << "found " << da << endl;
		return ;
	}
	return ;
}

void List::lsetVal(int da, int val)
{
	Node *p = head;
	while (p != NULL && p->data != da)
	{
		p=p->next;
	}

	if (p->data != da)
	{
		cout << "not found the node!" << endl;
		return ;
	}
	else
	{
		cout << "change No." << da << " value to " << val << endl;
		p->data = val;
		return ;
	}
}

void List::ldisplay()
{
	Node *p = head;
	while (p != tail)
	{
		cout << p->next->data << endl;
		p = p->next;
	}
}

int main()
{
	cout << "hello LinkList!" << endl;
	List l;
	l.linsert(1);
	l.linsert(2);
	l.linsert(3);
	l.linsert(4);
	l.linsert(5);
	l.linsert(6);
	l.linsert(7);
	l.ldelete(3);
	l.ldelete(7);
	l.ldisplay();
	l.lsearch(4);
	l.lsetVal(1, 100);
	l.lgetVal(6);
	cout << "display again" << endl;
	l.ldisplay();
	cin.get();
	return 0;
}