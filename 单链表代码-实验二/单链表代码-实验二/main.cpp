#include<iostream>  //ָ�����ļ��뵱ǰԴ�ļ�����һ��Դ�ļ�
#include<cstdlib>  //ϵͳ�����ͷ�ļ�ͨ��ʹ�ü����ţ��û��Զ����ͷ�ļ�ͨ��ʹ��˫����
#include "linkList.h"
using namespace std;   //�����ռ��еı�ʶ������ͬȫ�ֱ���һ��
//#include"seqList.h"
//#include"doubleLinkList.h"

template<class T>
void testList(List<T>* p)  //���Ժ������β���Ϊ����ָ��p,ʵ��Ϊ��������ַ
{
	if (p->empty())
		std::cout << "empty list\n";  //�п�
	int n, i;
	T val;
	std::cout << "input number of nodes;is\n";  //����������
	std::cin >> n;
	std::cout << "intput each node's insertion position and value:\n";
	while (n > 0)  //���Բ���
	{
		std::cin >> i;   //���������λ�õ��±�
		std::cin >> val;  //�������ֵ
		try
		{
			p->insert(i, val);  //����
		}
		catch (outRange)
		{
			cerr << "error,catch outRange\n";
		}
		n--;
	}
	p->traverse();  //���Ա���
	std::cout << "curLength:" << p->size() << endl;  //�����
	std::cout << "test inverse:\n";  //��������
	p->inverse();
	p->traverse();  //���Ա���
	std::cout << "test inverse:\n";
	std::cout << "input each node's insertion position and value:\n";
	std::cin >> i;
	std::cin >> val;
	p->insert(i, val);
	p->traverse();
	std::cout << "test search:\n";  //���Դ����Ա��в��������Ԫ��ֵ��ͬ��Ԫ�������Ա�
	std::cout << "input the value:\n";
	std::cin >> val;  //����Ҫ���ҵ�Ԫ��ֵ
	std::cout << "the position of" << val << "is :" << p->search(val) << endl;  //����
	std::cout << "test delete:\n";  //����ɾ��
	std::cout << "input the position:\n";
	std::cin >> i;  //����ɾ����λ��
	try
	{
		p->remove(i);  //ɾ��
	}
	catch (outOfRannge)
	{
		cerr << "error,catch outRange\n";
	}
	p->traverse();  //���Ա���

	std::cout << "test visit:\n"; //���Դ����Ա��в���Ԫ�أ�����λ��Ϊi��Ԫ��
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
	p->clear();  //�������
	if (p->empty())std::cout << "emptynlinkList\n";  //�п�
	p->traverse();  //���Ա���
}
template<class T>
void testLinkCreate(linkList<T>* p)
{
	std::cout << "test headCreate:\n";
	p->tailCreate();  //����ͷ�巨
	p->traverse();

	//p->outPut();
	p->clear();
	std::cout << "test tailCreate:\n";
	p->tailCreate();  //����β�巨
	p->traverse();

}
int main()
{
	linkList<int>* p;
	//seqList<int> *sq;
	p = new linkList<int>();  //����һ��������
	//sq = new seqLsit<int>(100);  //����һ��˳���

	//testLsit(sq)  //����˳���
	testList(p);  //���Ե�����

	testLinkCreate(p);

	system("pause");
	return 0;
}
