#ifndef _LINKLIST_H_  //
#define _LINKLIST_H_
//#include<stack>
#include"List.h"
using namespace std;
template<class elemType>  //elemTypeΪ������洢��Ԫ������
class linkList :public List<elemType> {
private:
	struct Node {
	public:
		elemType data;   //����������
		Node* next;  //�ڵ��ָ����ָ��������
		Node(const elemType value, Node* p = NULL) { //��������������Node���캯��
			data = value;
			next = p;

		}
		Node(Node* p = NULL) {
			next = p;
		}
		
	};
	Node* head;  //�������ͷָ��
		Node* tail;  //�������βָ��
		int curLength;  //������ĵ�ǰ����
		Node* getPosition(int i)const;  //����ָ�������е�i��Ԫ�ص�ָ��
public:
	linkList();  //���캯��
	~linkList();  //��������
	void clear();  //����������գ�ʹ֮��Ϊ�ձ�
	
	bool empty()const { return head->next == NULL; }  //�п�
	int size()const { return curLength; }  //���ص�����ĵ�ǰʵ�ʳ���
	void insert(int i, const elemType& value);  //��λ��i�ϲ���һ��Ԫ��value��
	void remove(int i);  //ɾ��λ��i�ϵ�Ԫ��value����ɾ��
	int search(const elemType& value)const;  //����ֵΪvalue��Ԫ�ص�һ�γ���
	elemType visit(int i)const;  //����λ��Ϊi��Ԫ��ֵ����λ��
	void traverse()const;  //����������
	void headCreate();  //��ͷ�巨������������
	void tailCreate();  //"β�巨"����������
	void inverse();  //���õ�����
	//int prior(const elemType&value)const;  //����ֵΪvalue��Ԫ�ص�ǰ��
	//linkList* Union(linkList<elemType> * lb);
	//void outPut();

};
template<class elemType>  //������ĳ�ʼ����ʱ�临�Ӷ�O(1)
linkList<elemType>::linkList() {
	head = tail = new Node();  //��������ͷ���Ŀձ�
	curLength = 0;
}
template<class elemType>
linkList<elemType>::~linkList() {
	clear();
	delete head;
}
template<class elemType>  //��յ�����ʱ�临�Ӷ�O(n)
void linkList<elemType>::clear() {
	Node* p, * tmp;  
	p = head->next;  //pΪ����ָ�룬(ע�ⲻҪ�����޸�ͷָ��)��ָ����Ԫ���
	while (p != NULL) {
		tmp = p;
		p = p->next;  //ָ�����
		delete tmp;
	}
	head->next = NULL;  //ͷ����ָ�����ÿ�
	tail = head;  //ͷβָ���ָ��ͷ���
	curLength = 0;
}
template<class elemType>  //����λ��Ϊi��Ԫ��
typename linkList<elemType>::Node* linkList<elemType>::getPosition(int i)const {
	Node* p = head;
	int count = 0;  //����ָ��pָ��ͷ���
	if (i<-1 || i>curLength - 1)  //getPosition�ɲ���λ��Ϊ[-1..n-1],��iΪ-1��
		return NULL;  //��i�Ƿ�ʱ����NULL
	while (count <= i) {
		p = p->next;
		count++;
	}
	return p;
}
template<class elemType>  //����Ԫ�أ�ʱ�临�Ӷ�O(n)
void linkList<elemType>::insert(int i, const elemType& value) {
	Node* p, * q;
	if (i<0 || i>curLength)  //�Ϸ��Ĳ���λ��Ϊ[0..n]
		throw outOfRange();  //����λ�÷Ƿ����׳��쳣
	p = getPosition(i - 1);  //p��λ��Ϊi�Ľ���ǰ��
	q = new Node(value, p->next);  //�����½ڵ�q
	p->next = q;  //q�����뵽p���ĺ���
	if (p == tail)tail = q;  //�����ڱ�β���������Ϊ�µ�β���
	curLength++;
}
template<class elemType>  //ɾ��Ԫ�أ�ʱ�临�Ӷ�O��n��
void linkList<elemType>::remove(int i) {
	Node* pre, * p;  //p�Ǵ�ɾ��㣬pre����ǰ��
	if (i<0 || i>curLength - 1)  //�Ϸ���ɾ��λ��Ϊ[0..n-1]
		throw outOfRange();  //����ɾ��㲻����ʱ���׳��쳣
	pre = getPosition(i - 1);  //p��λ��Ϊi�Ľ���ǰ��
	p = pre->next;  //p��������ɾ���
	if (p == tail) { //��ɾ��
		tail = pre;
		pre->next = NULL;
		delete p;
	}
	else {  //ɾ�����p,���޸�ָ��
		pre->next = p->next;
		delete p;
	}
	curLength--;
}


template<class elemType>  //��������ʱ�临�Ӷ�O(n)
void linkList<elemType>::traverse()const {
	Node* p = head->next;  //����ָ��pָ����Ԫ���
	cout << "traverse:";
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

}
template< class elemType>  //����ֵΪvalue��Ԫ�ص�λ��
int linkList<elemType>::search(const elemType& value)const {
	Node* p = head->next;  //����ָ��pָ����Ԫ���
	int count = 0;  //��Ԫ����λ��Ϊ0
	while (p != NULL && p->data != value) {
		p = p->next;
		count++;

	}
	if (p == NULL)return -1;  //����ʧ�ܷ���-1������-1����ͷ�ڵ�
	else return count;
}

template<class elemType>  //����λ��Ϊi��Ԫ�ط�����������
elemType linkList<elemType>::visit(int i)const {
	Node* p = head->next;
	int count = 0;  //��Ԫ���λ��Ϊ0
	if (i<0 || i>curLength - 1)  //�Ϸ��ķ���λ��Ϊ[0..n-1]
		throw outOfRange();  //����㲻����ʱ���׳��쳣
	while (count < i) {
		p = p->next;
		count++;
		
	}
	return p->data;
}
template<class elemType>  //ͷ�巨����������ʱ�临�Ӷ�O(n)
void linkList<elemType>::headCreate() {
	Node* p;
	elemType value, flag;
	cout << "input elements,ended with:";
	cin >> flag;  //���������־
	while (cin >> value, value != flag)
	{
		//�����½��p->data = value,p->next = head->next
		p = new Node(value, head->next);
		head->next = p;  //���p���뵽ͷ���ĺ���
		if (head == tail)tail = p;  //ԭ����Ϊ�գ�����p��β���
		curLength++;
	}
}
template<class elemType>  //β�巨��������ʱ�临�Ӷ�ΪO(n)
void linkList<elemType>::tailCreate() {
	Node* p;
	elemType value, flag;
	cout << "input elements,ended with:";
	cin >> flag;  //���������־
	while (cin >> value, value != flag)
	{
		p = new Node(value, NULL);
		tail->next = p;   //�����뵽β���ĺ���
		tail = p;
		curLength++;  
	}
}
template<class elemType >  //ͷ�巨���ã�ʱ�临�Ӷ�O(n)
void linkList<elemType>::inverse() {
	Node* p, * tmp;   
	p = head->next;   //pΪ����ָ��ָ����Ԫ���
	head->next = NULL;  //����ֻ��һ��ͷ���Ŀ�����
	if (p)tail = p;   //ԭ��Ԫ��㽫��ɱ�β
	while (p)
	{
		tmp = p->next;   //���浱ǰ������p�ĺ��
		p->next = head-> next;
		head->next = p;    //���p���뵽ͷ���ĺ���
		p = tmp;
	}
}
#endif
