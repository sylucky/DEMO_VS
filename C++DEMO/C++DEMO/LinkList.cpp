#include "LinkList.h"

using namespace std;

StuInfo::StuInfo(string id, string name, string gender, int age)
{
	stuid = id;
	stuname = name;
	stugender = gender;
	stuage = age;
}
StuInfo::StuInfo()
{
	stuage = 0;
}

StuInfo::~StuInfo()
{

}

void StuInfo::stuCopy(StuInfo s)
{
	stuid = s.stuid;
	stuname = s.stuname;
	stugender = s.stugender;
	stuage = s.stuage;
}

void StuInfo::stuDisplay()
{
	cout << stuid << " , " << stuname << " , " << stugender << " , " << stuage << endl;
}

Node::Node(int seq, StuInfo s)
{
	this->sinfo.stuCopy(s);
	this->next = NULL;
	this->seqno = seq;
}

Node::Node()
{
	seqno = 0;
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

void List::lInsert(int seq, StuInfo s)
{
	if (head == NULL)//insert seq first
	{
		head = new Node();
		tail = new Node(seq, s);
		head->next = tail;
	}
	else
	{
		Node *inode = new Node(seq, s);
		tail->next = inode;
		tail = inode;
	}
}

void List::lDelete(int seq)
{
	Node *p;
	p = head;
	if (head == NULL)
	{
		cout << "LinkList is empty!" << endl;
		return;
	}
	//遍历链表
	while (p->next != NULL && p->next->seqno != seq)
	{
		p = p->next;
	}

	if (p->next == NULL || p->next->seqno != seq)
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
	cout << "delete the No." << seq << ": ";
	p->sinfo.stuDisplay();
}

int List::lSearch(int seq)
{
	Node *p = head;
	while (p != NULL && p->seqno != seq)
	{
		p = p->next;
	}

	if (p == NULL || p->seqno != seq)
	{
		cout << "not found the node!" << endl;
		return -1;
	}
	else
	{
		cout << "found the No." << seq << ": ";
		p->sinfo.stuDisplay();
		return seq;
	}

	return -1;
}

void List::lgetVal(int seq)
{
	Node *p = head;
	while (p != NULL && p->seqno != seq)
	{
		p = p->next;
	}

	if (p == NULL || p->seqno != seq)
	{
		cout << "not found the node!" << endl;
		return;
	}
	else
	{
		cout << "found " << seq << endl;
		return;
	}
	return;
}

void List::lSetVal(int seq, StuInfo s)
{
	Node *p = head;
	while (p != NULL && p->seqno != seq)
	{
		p = p->next;
	}

	if (p == NULL || p->seqno != seq)
	{
		cout << "not found the node!" << endl;
		return;
	}
	else
	{
		cout << "change No." << seq << ": ";
		p->sinfo.stuCopy(s);
		p->sinfo.stuDisplay();
		return;
	}
}

void List::lDisplay()
{
	Node *p = head;
	while (p != tail)
	{
		p->next->sinfo.stuDisplay();
		p = p->next;
	}
}

//test main
//4 student objects execute display, delete, search, setval, display operation
int main()
{
	int i = 1;
	cout << "hello LinkList!" << endl;
	List l;
	l.lInsert(i++, StuInfo("1001", "张三", "男", 18));
	l.lInsert(i++, StuInfo("1002", "李四", "男", 19));
	l.lInsert(i++, StuInfo("1003", "王五", "女", 20));
	l.lInsert(i++, StuInfo("1004", "赵六", "女", 21));
	l.lDisplay();
	l.lDelete(2);
	l.lSearch(1);
	l.lSetVal(1, StuInfo("1001", "张小红", "女", 22));
	cout << "display again" << endl;
	l.lDisplay();
	cin.get();
	return 0;
}
