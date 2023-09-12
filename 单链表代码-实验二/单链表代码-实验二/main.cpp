#include<iostream>  //指定的文件与当前源文件连成一个源文件
#include<cstdlib>  //系统定义的头文件通常使用尖括号；用户自定义的头文件通常使用双引号
#include "linkList.h"
using namespace std;   //命名空间中的标识符就如同全局变量一样
//#include"seqList.h"
//#include"doubleLinkList.h"

template<class T>
void testList(List<T>* p)  //测试函数，形参作为父类指针p,实参为子类对象地址
{
	if (p->empty())
		std::cout << "empty list\n";  //判空
	int n, i;
	T val;
	std::cout << "input number of nodes;is\n";  //输入结点总数
	std::cin >> n;
	std::cout << "intput each node's insertion position and value:\n";
	while (n > 0)  //测试插入
	{
		std::cin >> i;   //输入结点插入位置的下标
		std::cin >> val;  //输入结点的值
		try
		{
			p->insert(i, val);  //插入
		}
		catch (outRange)
		{
			cerr << "error,catch outRange\n";
		}
		n--;
	}
	p->traverse();  //测试遍历
	std::cout << "curLength:" << p->size() << endl;  //输出表长
	std::cout << "test inverse:\n";  //测试逆置
	p->inverse();
	p->traverse();  //测试遍历
	std::cout << "test inverse:\n";
	std::cout << "input each node's insertion position and value:\n";
	std::cin >> i;
	std::cin >> val;
	p->insert(i, val);
	p->traverse();
	std::cout << "test search:\n";  //测试从线性表中查找与给定元素值相同的元素在线性表
	std::cout << "input the value:\n";
	std::cin >> val;  //输入要查找的元素值
	std::cout << "the position of" << val << "is :" << p->search(val) << endl;  //查找
	std::cout << "test delete:\n";  //测试删除
	std::cout << "input the position:\n";
	std::cin >> i;  //输入删除的位置
	try
	{
		p->remove(i);  //删除
	}
	catch (outOfRannge)
	{
		cerr << "error,catch outRange\n";
	}
	p->traverse();  //测试遍历

	std::cout << "test visit:\n"; //测试从线性表中查找元素，访问位序为i的元素
	std::cout << "input the position[0..n-1]:\n";
	std::cin >> i;
	try
	{
		std::cout << "position[0..n-1]:\n";
	}
	catch (outRange)
	{
		cerr << "error,catch outRange\n";
	}
	std::cout << "test clear:\n";
	p->clear();  //测试清空
	if (p->empty())std::cout << "emptynlinkList\n";  //判空
	p->traverse();  //测试遍历
}
template<class T>
void testLinkCreate(linkList<T>* p)
{
	std::cout << "test headCreate:\n";
	p->tailCreate();  //测试头插法
	p->traverse();

	//p->outPut();
	p->clear();
	std::cout << "test tailCreate:\n";
	p->tailCreate();  //测试尾插法
	p->traverse();

}
int main()
{
	linkList<int>* p;
	//seqList<int> *sq;
	p = new linkList<int>();  //创建一个单链表
	//sq = new seqLsit<int>(100);  //创建一个顺序表

	//testLsit(sq)  //测试顺序表
	testList(p);  //测试单链表

	testLinkCreate(p);

	system("pause");
	return 0;
}
