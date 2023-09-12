#ifndef _LINKLIST_H_  //
#define _LINKLIST_H_
//#include<stack>
#include"List.h"
using namespace std;
template<class elemType>  //elemType为单链表存储的元素类型
class linkList :public List<elemType> {
private:
	struct Node {
	public:
		elemType data;   //结点的数据域
		Node* next;  //节点的指针域，指向后继续点
		Node(const elemType value, Node* p = NULL) { //具有两个参数的Node构造函数
			data = value;
			next = p;

		}
		Node(Node* p = NULL) {
			next = p;
		}
		
	};
	Node* head;  //单链表的头指针
		Node* tail;  //单链表的尾指针
		int curLength;  //单链表的当前长度
		Node* getPosition(int i)const;  //返回指向单链表中第i个元素的指针
public:
	linkList();  //构造函数
	~linkList();  //析构函数
	void clear();  //将单链表清空，使之成为空表
	
	bool empty()const { return head->next == NULL; }  //判空
	int size()const { return curLength; }  //返回单链表的当前实际长度
	void insert(int i, const elemType& value);  //在位置i上插入一个元素value，
	void remove(int i);  //删除位置i上的元素value，若删除
	int search(const elemType& value)const;  //查找值为value的元素第一次出现
	elemType visit(int i)const;  //访问位序为i的元素值，“位序”
	void traverse()const;  //遍历单链表
	void headCreate();  //“头插法”创建单链表
	void tailCreate();  //"尾插法"创建单链表
	void inverse();  //逆置单链表
	//int prior(const elemType&value)const;  //查找值为value的元素的前驱
	//linkList* Union(linkList<elemType> * lb);
	//void outPut();

};
template<class elemType>  //单链表的初始化，时间复杂度O(1)
linkList<elemType>::linkList() {
	head = tail = new Node();  //创建带有头结点的空表
	curLength = 0;
}
template<class elemType>
linkList<elemType>::~linkList() {
	clear();
	delete head;
}
template<class elemType>  //清空单链表，时间复杂度O(n)
void linkList<elemType>::clear() {
	Node* p, * tmp;  
	p = head->next;  //p为工作指针，(注意不要随意修改头指针)，指向首元结点
	while (p != NULL) {
		tmp = p;
		p = p->next;  //指针后移
		delete tmp;
	}
	head->next = NULL;  //头结点的指针域置空
	tail = head;  //头尾指针均指向头结点
	curLength = 0;
}
template<class elemType>  //查找位序为i的元素
typename linkList<elemType>::Node* linkList<elemType>::getPosition(int i)const {
	Node* p = head;
	int count = 0;  //工作指针p指向头结点
	if (i<-1 || i>curLength - 1)  //getPosition可查找位置为[-1..n-1],若i为-1则定
		return NULL;  //当i非法时返回NULL
	while (count <= i) {
		p = p->next;
		count++;
	}
	return p;
}
template<class elemType>  //插入元素，时间复杂度O(n)
void linkList<elemType>::insert(int i, const elemType& value) {
	Node* p, * q;
	if (i<0 || i>curLength)  //合法的插入位置为[0..n]
		throw outOfRange();  //插入位置非法，抛出异常
	p = getPosition(i - 1);  //p是位序为i的结点的前驱
	q = new Node(value, p->next);  //申请新节点q
	p->next = q;  //q结点插入到p结点的后面
	if (p == tail)tail = q;  //插入在表尾，插入结点成为新的尾结点
	curLength++;
}
template<class elemType>  //删除元素，时间复杂度O（n）
void linkList<elemType>::remove(int i) {
	Node* pre, * p;  //p是待删结点，pre是其前驱
	if (i<0 || i>curLength - 1)  //合法的删除位置为[0..n-1]
		throw outOfRange();  //当待删结点不存在时，抛出异常
	pre = getPosition(i - 1);  //p是位序为i的结点的前驱
	p = pre->next;  //p是真正待删结点
	if (p == tail) { //待删除
		tail = pre;
		pre->next = NULL;
		delete p;
	}
	else {  //删除结点p,并修改指针
		pre->next = p->next;
		delete p;
	}
	curLength--;
}


template<class elemType>  //遍历链表，时间复杂度O(n)
void linkList<elemType>::traverse()const {
	Node* p = head->next;  //工作指针p指向首元结点
	cout << "traverse:";
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

}
template< class elemType>  //查找值为value的元素的位置
int linkList<elemType>::search(const elemType& value)const {
	Node* p = head->next;  //工作指针p指向首元结点
	int count = 0;  //首元结点的位序为0
	while (p != NULL && p->data != value) {
		p = p->next;
		count++;

	}
	if (p == NULL)return -1;  //查找失败返回-1，这里-1并非头节点
	else return count;
}

template<class elemType>  //访问位序为i的元素返回其数据域
elemType linkList<elemType>::visit(int i)const {
	Node* p = head->next;
	int count = 0;  //首元结点位序为0
	if (i<0 || i>curLength - 1)  //合法的访问位置为[0..n-1]
		throw outOfRange();  //当结点不存在时，抛出异常
	while (count < i) {
		p = p->next;
		count++;
		
	}
	return p->data;
}
template<class elemType>  //头插法创建单链表，时间复杂度O(n)
void linkList<elemType>::headCreate() {
	Node* p;
	elemType value, flag;
	cout << "input elements,ended with:";
	cin >> flag;  //输入结束标志
	while (cin >> value, value != flag)
	{
		//创建新结点p->data = value,p->next = head->next
		p = new Node(value, head->next);
		head->next = p;  //结点p插入到头结点的后面
		if (head == tail)tail = p;  //原链表为空，则结点p是尾结点
		curLength++;
	}
}
template<class elemType>  //尾插法创建链表，时间复杂度为O(n)
void linkList<elemType>::tailCreate() {
	Node* p;
	elemType value, flag;
	cout << "input elements,ended with:";
	cin >> flag;  //输入结束标志
	while (cin >> value, value != flag)
	{
		p = new Node(value, NULL);
		tail->next = p;   //结点插入到尾结点的后面
		tail = p;
		curLength++;  
	}
}
template<class elemType >  //头插法逆置，时间复杂度O(n)
void linkList<elemType>::inverse() {
	Node* p, * tmp;   
	p = head->next;   //p为工作指针指向首元结点
	head->next = NULL;  //构成只有一个头结点的空链表
	if (p)tail = p;   //原首元结点将变成表尾
	while (p)
	{
		tmp = p->next;   //保存当前处理结点p的后继
		p->next = head-> next;
		head->next = p;    //结点p插入到头结点的后面
		p = tmp;
	}
}
#endif
