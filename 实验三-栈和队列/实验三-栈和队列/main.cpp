#include<cstdlib>
#include<iostream>
#include<stack>
using namespace std;
#include"linkStack.h"
#include"seqStack.h"



template<class T>
void testStack(Stack<T>& s)
{
	cout << "²âÊÔÈëÕ»" << endl;
	for (int i = 0;i < 20;++i) {
		s.push(2 * i);
		cout << "curLength=" << s.size() << endl;
	}
	cout << "curLength=" << s.size() << endl;
	cout << "²âÊÔÈ¡Õ»¶¥ÔªËØ" << endl;
	cout << "Õ»¶¥ÔªËØÎª:" << s.getTop() << endl;
	cout << "²âÊÔÇå¿ÕÕ»" << endl;
	s.clear();
	cout << "curLength=" << s.size() << endl;
	for (int i = 0;i < 10;++i) {
		s.push(2 * i);
		cout << "curLength=" << s.size() << endl;
	}
	cout << "curLength=" << s.size() << endl;
	cout << "²âÊÔÍËÕ»" << endl;
	while (!s.empty())cout << s.pop() << ' ';
	cout << "\ncurLength=" << s.size() << endl;
	try {
		cout << s.getTop();
	}
	catch (outOfRange& me) {
		cout << me.what();
	}
}
//²âÊÔÕ»
int main()
{
	seqStack<int> ss;
	linkStack<int> ls;
	testStack(ss);
	testStack(ls);
	system("pause");
	return 0;
}