//����seqStack˳��ջ��
//array-based stack; definition and implementation for some methods

#ifndef _SEQSTACK_H_
#define _SEQSTACK_H_

#include"Stack.h"
template <class T>
class seqStack : public Stack<T>
{
	T* data;  //���ջ��Ԫ�ص�����
	int top;  //ջ��ָ�룬ָ��ջ��Ԫ��
	int maxSize;  //ջ�Ĵ�С
	void resize();  //����ջ�Ŀռ�
public:
	seqStack(int initSize = 100) { //��ʼ��һ���յ�˳��ջ����ջ����topΪ-1
		if (initSize <= 0) throw badSize();
		data = new T[initSize];
		maxSize = initSize;
		top = -1;
    	}
	~seqStack() { delete[] data; }
	bool empty() const { return top == -1; }  //�п�
	int size() const { return top + 1; }  //�󳤶�
	void clear() { top = -1; }   //���ջ
	void push(const T& value);  //��ջ
	T pop();  //��ջ
	T getTop() const;  //ȡջ��Ԫ��
};

template <class T>
void seqStack<T>::resize(){  //����ջ�ռ�
	T* tmp = data;
	data = new T[2 * maxSize];
	for (int i = 0;i < maxSize; ++i) 
		data[i] = tmp[i];
	maxSize *= 2;
	delete [] tmp;
	
}
template <class T>
void seqStack<T> ::push(const T &value){//��ջ
	if (top == maxSize - 1)  resize();
	data[++top] = value;
}
template <class T>
T seqStack<T> ::pop(){  //��ջ
	if (empty())throw outOfRange();
	return data[top--];
}
template <class T>
T seqStack<T> ::getTop() const {  //ȡջ��Ԫ��
	if (empty())throw outOfRange();
	return data[top];

}
#endif