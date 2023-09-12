#include<queue>
#include<stack>
#include<iostream>
#include<cstdlib>
using namespace std;
#include"BinaryLinkedList.h"

template <class T>
void testBinaryTree(BinaryLinkList<T>& tree)
{
	cout << "输入带外部结点的前序遍历序列（*表示NULL为外部结点）：";
	tree.preOrderCreate('*');
	cout << "高度为：" << tree.height() << endl;
	cout << "规模为：" << tree.size() << endl;
	cout << "叶子数：" << tree.leafNum() << endl;

	//递归方式前序 中序 后序遍历
	cout << "递归前序遍历："; tree.preOrderTraverse();
	cout << "\n递归中序遍历：";  tree.inOrderTraverse();
	cout << "\n递归后序遍历"; tree.postOrderTraverse();
	
	//非递归方式前序 中序 后序遍历
	cout <<"\n非递归前序遍历："; tree.preOrderWithStack();
	cout << "\n非递归中序遍历：";tree.inOrderWithStack();
	cout << "\n非递归后序遍历："; tree.postOrderWithStack();

	//层次遍历
	cout << "\n层次遍历："; tree.levelOrderTraverse();

	tree.clear();  //测试清空
	cout << "\n规模为：" << tree.size() << endl;
	if (tree.empty())cout << "empty tree" << endl; //测试判空


}
int main()
{
	BinaryLinkList<char> tree;
	testBinaryTree(tree);
	system("pause");
	return 0;
}