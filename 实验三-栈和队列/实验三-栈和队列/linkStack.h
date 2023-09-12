// 保存linkStack链栈类
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
	Node* top;   //栈顶指针
public:
	linkStack() { top = NULL; }  //构造空栈
	~linkStack() { clear(); }
	void clear();  //清空栈
	bool empty()const {return top == NULL;} //   判空
	int size()const;  //求长度
	void push(const T& value);  //入栈
	T pop();  //退栈
	T getTop()const;  //取栈顶元素

};

template<class T>
void linkStack<T>::clear(){  //清空栈
	Node* p;
	while (top != NULL) {
		p = top;
		top = top->next;
		delete p;
	}
}
template <class T>
int linkStack<T>::size() const{  //求长度
	Node* p = top;
	int count =0 ;
	while (p) {
		count++;
		p = p->next;
	}
	return count;

}
template <class T>
void linkStack<T> ::push(const T &value){//入栈
	Node* p = new Node(value, top);
	top = p;
}
template <class T>
T linkStack<T>::pop(){  //退栈
	if (empty())throw outOfRange();
	Node* p = top;
	T value = p->data;
	top = top->next;
	delete p;
	return value;
}
template <class T>
T linkStack<T>::getTop() const {  //取栈顶元素
	if (empty())throw outOfRange();
	return top->data;

}
#endif