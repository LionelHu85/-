//Stack.h头文件，保存Stack抽象类
//abstract data type for stack
#ifndef _STACK_H_
#define _STACK_H_

class outOfRange :public exception {  //用于检查范围的有效性
public:
	const char* what()const throw()
	
		{return "ERROR! OUT OF RANGE.\n";}
};
	
class badSize :public exception {  //用于检查长度的有效性
public:
	const char* what() const throw() {
		return "ERROR! BAD SIZE.\n";
	}

};
template <class T>  //栈的元素类型为T
class Stack
{
public:
	virtual bool empty() const = 0; // 判空
	virtual int size() const = 0;  //求栈中元素个数
	virtual void push(const T& x) = 0;  //压栈，插入元素x为新的栈项元素
	virtual T pop() = 0;  //弹栈，若栈非空，则删除栈项元素
	virtual T getTop() const = 0;  //取栈项元素，返回栈项元素但不弹出
	virtual void clear() = 0; // 清空栈
	virtual ~Stack() {}
};
#endif