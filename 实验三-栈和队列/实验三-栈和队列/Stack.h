//Stack.hͷ�ļ�������Stack������
//abstract data type for stack
#ifndef _STACK_H_
#define _STACK_H_

class outOfRange :public exception {  //���ڼ�鷶Χ����Ч��
public:
	const char* what()const throw()
	
		{return "ERROR! OUT OF RANGE.\n";}
};
	
class badSize :public exception {  //���ڼ�鳤�ȵ���Ч��
public:
	const char* what() const throw() {
		return "ERROR! BAD SIZE.\n";
	}

};
template <class T>  //ջ��Ԫ������ΪT
class Stack
{
public:
	virtual bool empty() const = 0; // �п�
	virtual int size() const = 0;  //��ջ��Ԫ�ظ���
	virtual void push(const T& x) = 0;  //ѹջ������Ԫ��xΪ�µ�ջ��Ԫ��
	virtual T pop() = 0;  //��ջ����ջ�ǿգ���ɾ��ջ��Ԫ��
	virtual T getTop() const = 0;  //ȡջ��Ԫ�أ�����ջ��Ԫ�ص�������
	virtual void clear() = 0; // ���ջ
	virtual ~Stack() {}
};
#endif