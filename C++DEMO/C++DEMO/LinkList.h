//single direction link list
//the data of head is null
//the pointer of tail is null
#include <iostream>
#include <string>
using namespace std;

//class datatype, record the student's info
class StuInfo
{
public:
	StuInfo(string id, string name, string gender, int age);
	StuInfo();
	~StuInfo();
	void stuCopy(StuInfo s);
	void stuDisplay();
private:
	string stuid;
	string stuname;
	string stugender;
	int stuage;
};

//node of link list,include counter, the next pointer,and student data.
class Node
{
public:
	Node(int seq, StuInfo s);
	Node();//for head porinter only
	~Node();
	StuInfo sinfo;
	Node *next;
	int seqno;
};

//µ•œÚ¡¥±Ì Unidirectional linked list
class List
{
public:
	List();
	~List();
	void lInsert(int seq, StuInfo s);//link list tail insert
	void lDelete(int seq);//delete anyone node
	int lSearch(int seq);//get anyone node
	void lgetVal(int po);
	void lSetVal(int seq, StuInfo s);//set anyone node
	void lDisplay();//display the whole link list
private:
	Node *head, *tail;
	int position;
};
