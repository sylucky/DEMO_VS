#include "LinkList.h"

using namespace std;

StuInfo::StuInfo(string id, string name, string gender, int age)
{
	stuId = id;
	stuName = name;
	stuGender = gender;
	stuAge = age;
}
StuInfo::StuInfo()
{
	stuAge = 0;
}

StuInfo::~StuInfo()
{

}

void StuInfo::stuCopy(StuInfo s)
{
	stuId = s.stuId;
	stuName = s.stuName;
	stuGender = s.stuGender;
	stuAge = s.stuAge;
}

void StuInfo::stuDisplay()
{
	cout << stuId << " , " << stuName << " , " << stuGender << " , " << stuAge << endl;
}

template<typename T>
Node<T>::Node(int seq, T temp)
{
	this->t.stuCopy(temp);
	this->next = NULL;
	this->seqno = seq;
}

template<typename T>
Node<T>::Node(int seq)
{
	seqno = seq;
	next = NULL;
}

template<typename T>
Node<T>::~Node()
{
	next = NULL;
}

List::List()
{
	position = 0;
	head = NULL;
	tail = NULL;
}

List::~List()
{
	delete head;
	delete tail;
}

void List::insertNode(Node<StuInfo> *n)
{
	if (head == NULL)//insert seq first
	{
		head = n;
		tail = n;
		cout << "1" << endl;
		head->t.stuDisplay();
		cout << "end" << endl;
	}
	else
	{
		tail->next = n;
		tail = n;
		cout << "2" << endl;
	}
}

void List::deleteNode(int seq)
{
	Node<StuInfo> *p;
	p = head;
	if (head->next == NULL)
	{
		cout << "LinkList is empty!" << endl;
		return;
	}
	//遍历链表
	while (p->next != NULL && p->next->getSeq() != seq)
	{
		cout << "LinkList is empty!" << p->next->getSeq() << "," << seq << endl;
		p->next->t.stuDisplay();
		p = p->next;
	}

	if (p->next == NULL || p->next->getSeq() != seq)
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
	p->t.stuDisplay();
}

int List::searchNode(int seq)
{
	Node<StuInfo> *p = head;
	while (p != NULL && p->getSeq() != seq)
	{
		p = p->next;
	}

	if (p == NULL || p->getSeq() != seq)
	{
		cout << "not found the node!" << endl;
		return -1;
	}
	else
	{
		cout << "found the No." << seq << ": ";
		p->t.stuDisplay();
		return seq;
	}

	return -1;
}

void List::getNodeVal(int seq)
{
	Node<StuInfo> *p = head;
	while (p != NULL && p->getSeq() != seq)
	{
		p = p->next;
	}

	if (p == NULL || p->getSeq() != seq)
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

void List::setNodeVal(int seq, Node<StuInfo> n)
{
	Node<StuInfo> *inode = &n;
	Node<StuInfo> *p = head;
	while (p != NULL && p->getSeq() != seq)
	{
		p = p->next;
	}

	if (p == NULL || p->getSeq() != seq)
	{
		cout << "not found the node!" << endl;
		return;
	}
	else
	{
		cout << "change No." << seq << ": ";
		p = inode;
		p->t.stuDisplay();
		return;
	}
}

void List::displayList() const
{
	Node<StuInfo> *p = head;
	while (p != NULL)
	{
		p->t.stuDisplay();
		p = p->next;
	}
}

//test main
//4 student objects execute display, delete, search, setval, display operation
int main()
{
	int i = 1;
	cout << "hello LinkList!" << endl;
	List list;

	Node<StuInfo> stu1(i++, StuInfo("1001", "张三", "男", 18));
	Node<StuInfo> stu2(i++, StuInfo("1002", "李四", "男", 19));
	Node<StuInfo> stu3(i++, StuInfo("1003", "王五", "女", 20));
	Node<StuInfo> stu4(i++, StuInfo("1004", "赵六", "女", 21));
	list.insertNode(&stu1);
	list.insertNode(&stu2);
	list.insertNode(&stu3);
	list.insertNode(&stu4);
	list.displayList();
	list.deleteNode(2);
	list.searchNode(1);
	list.setNodeVal(1, Node<StuInfo>(1, StuInfo("1001", "张小红", "女", 22)));
	cout << "display again" << endl;
	list.displayList();
	cin.get();
	return 0;
}
