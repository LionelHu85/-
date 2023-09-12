//保存seqStack顺序栈类
//array-based stack; definition and implementation for some methods

#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

#include"Stack.h"
template <class T>
class seqStack : public Stack<T>
{
	T* data;  //存放栈中元素的数组
	int top;  //栈项指针，指向栈项元素
	int maxSize;  //栈的大小
	void resize();  //扩大栈的空间
public:
	seqStack(int initSize = 100) { //初始化一个空的顺序栈，置栈顶针top为-1
		if (initSize <= 0) throw badSize();
		data = new T[initSize];
		maxSize = initSize;
		top = -1;
    	}
	~seqStack() { delete[] data; }
	bool empty() const { return top == -1; }  //判空
	int size() const { return top + 1; }  //求长度
	void clear() { top = -1; }   //清空栈
	void push(const T& value);  //入栈
	T pop();  //退栈
	T getTop() const;  //取栈顶元素
};

template <class T>
void seqStack<T>::resize(){  //扩大栈空间
	T* tmp = data;
	data = new T[2 * maxSize];
	for (int i = 0;i < maxSize; ++i) 
		data[i] = tmp[i];
	maxSize *= 2;
	delete [] tmp;
	
}
template <class T>
void seqStack<T> ::push(const T &value){//入栈
	if (top == maxSize - 1)  resize();
	data[++top] = value;
}
template <class T>
T seqStack<T> ::pop(){  //退栈
	if (empty())throw outOfRange();
	return data[top--];
}
template <class T>
T seqStack<T> ::getTop() const {  //取栈顶元素
	if (empty())throw outOfRange();
	return data[top];

}
#endif