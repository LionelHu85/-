#include<queue>
#include<stack>
#include<iostream>
#include<cstdlib>
using namespace std;
#include"BinaryLinkedList.h"

template <class T>
void testBinaryTree(BinaryLinkList<T>& tree)
{
	cout << "������ⲿ����ǰ��������У�*��ʾNULLΪ�ⲿ��㣩��";
	tree.preOrderCreate('*');
	cout << "�߶�Ϊ��" << tree.height() << endl;
	cout << "��ģΪ��" << tree.size() << endl;
	cout << "Ҷ������" << tree.leafNum() << endl;

	//�ݹ鷽ʽǰ�� ���� �������
	cout << "�ݹ�ǰ�������"; tree.preOrderTraverse();
	cout << "\n�ݹ����������";  tree.inOrderTraverse();
	cout << "\n�ݹ�������"; tree.postOrderTraverse();
	
	//�ǵݹ鷽ʽǰ�� ���� �������
	cout <<"\n�ǵݹ�ǰ�������"; tree.preOrderWithStack();
	cout << "\n�ǵݹ����������";tree.inOrderWithStack();
	cout << "\n�ǵݹ���������"; tree.postOrderWithStack();

	//��α���
	cout << "\n��α�����"; tree.levelOrderTraverse();

	tree.clear();  //�������
	cout << "\n��ģΪ��" << tree.size() << endl;
	if (tree.empty())cout << "empty tree" << endl; //�����п�


}
int main()
{
	BinaryLinkList<char> tree;
	testBinaryTree(tree);
	system("pause");
	return 0;
}