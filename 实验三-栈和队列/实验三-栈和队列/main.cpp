#include<cstdlib>
#include<iostream>
#include<stack>
using namespace std;
#include"linkStack.h"
#include"seqStack.h"



template<class T>
void testStack(Stack<T>& s)
{
	cout << "������ջ" << endl;
	for (int i = 0;i < 20;++i) {
		s.push(2 * i);
		cout << "curLength=" << s.size() << endl;
	}
	cout << "curLength=" << s.size() << endl;
	cout << "����ȡջ��Ԫ��" << endl;
	cout << "ջ��Ԫ��Ϊ:" << s.getTop() << endl;
	cout << "�������ջ" << endl;
	s.clear();
	cout << "curLength=" << s.size() << endl;
	for (int i = 0;i < 10;++i) {
		s.push(2 * i);
		cout << "curLength=" << s.size() << endl;
	}
	cout << "curLength=" << s.size() << endl;
	cout << "������ջ" << endl;
	while (!s.empty())cout << s.pop() << ' ';
	cout << "\ncurLength=" << s.size() << endl;
	try {
		cout << s.getTop();
	}
	catch (outOfRange& me) {
		cout << me.what();
	}
}
//����ջ
int main()
{
	seqStack<int> ss;
	linkStack<int> ls;
	testStack(ss);
	testStack(ls);
	system("pause");
	return 0;
}