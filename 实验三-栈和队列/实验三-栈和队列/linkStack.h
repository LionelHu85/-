// ����linkStack��ջ��
#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
#include "Stack.h"

template <class T>
class linkStack : public Stack<T>
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node() { next = NULL; }
		Node(const T& value, Node* p = NULL) { data = value; next = p; }
	};
	Node* top;   //ջ��ָ��
public:
	linkStack() { top = NULL; }  //�����ջ
	~linkStack() { clear(); }
	void clear();  //���ջ
	bool empty()const {return top == NULL;} //   �п�
	int size()const;  //�󳤶�
	void push(const T& value);  //��ջ
	T pop();  //��ջ
	T getTop()const;  //ȡջ��Ԫ��

};

template<class T>
void linkStack<T>::clear(){  //���ջ
	Node* p;
	while (top != NULL) {
		p = top;
		top = top->next;
		delete p;
	}
}
template <class T>
int linkStack<T>::size() const{  //�󳤶�
	Node* p = top;
	int count =0 ;
	while (p) {
		count++;
		p = p->next;
	}
	return count;

}
template <class T>
void linkStack<T> ::push(const T &value){//��ջ
	Node* p = new Node(value, top);
	top = p;
}
template <class T>
T linkStack<T>::pop(){  //��ջ
	if (empty())throw outOfRange();
	Node* p = top;
	T value = p->data;
	top = top->next;
	delete p;
	return value;
}
template <class T>
T linkStack<T>::getTop() const {  //ȡջ��Ԫ��
	if (empty())throw outOfRange();
	return top->data;

}
#endif