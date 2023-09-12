#ifndef _BINARY_LINKLIST_H_
#define _BINARY_LINKLIST_H_
#include"BinaryTree.h"

template <class elemType>
class BinaryLinkList:public binaryTree<elemType> {
private:
	struct Node{
		Node *left , *right;  //ָ�����Һ��ӵ�ָ��
		elemType data;
		Node() : left(NULL),right(NULL) { }  //�޲ι��캯��
		Node(elemType value, Node * l = NULL, Node * r = NULL) {
			data = value; left = l;right = r;
		}
		~Node() {}


	};
	enum Tags{Left,Right};
	struct StackElement
	{
		Node* pointer;
		Tags tag;
		StackElement() {

		}
	};
	Node* root;   //ָ��������ĸ��ڵ�
	void clear(Node* t);
	int size(Node* t)const;
	int height(Node* t)const;
	int leafNum(Node* t)const;
	void preOrder(Node* t) const;  //�ݹ�ǰ�����
	void inOrder(Node* t) const;  //�ݹ��������
	void postOrder(Node* t) const;  //�ݹ�������
	void preOrderCreate(elemType flag, Node*& t);  //ע��tΪ����
public:
	BinaryLinkList() : root(NULL) {}  //����ն�����
	~BinaryLinkList() { clear(); }
	bool empty() const { return root == NULL; }   //�п�
	void clear() { if (root) clear(root); root = NULL; } //���
	int size() const { return size(root); }  //�������Ľ������
	int height() const { return height(root); }  //�������ĸ߶�
	int leafNum() const { return leafNum(root); }  //��������Ҷ����
	void preOrderTraverse() const { if (root) preOrder(root); }  //ǰ�����
	void inOrderTraverse() const { if (root) inOrder(root); }  //�������
	void postOrderTraverse() const { if (root) postOrder(root); }  //��������
	void levelOrderTraverse() const;  //��α���
	void preOrderWithStack() const;  //�ǵݹ�ǰ�����
	void inOrderWithStack() const;  //�ǵݹ��������
	void postOrderWithStack() const;  //�ǵݹ�������
	void levelOrderCreate(elemType flag);  //���ô��ⲿ���Ĳ�����д���������
	void preOrderCreate(elemType flag) {  //���ô��ⲿ����ǰ�����д���������
		preOrderCreate(flag, root);
	}
	void makeTree(const elemType& value, BinaryLinkList& lt, BinaryLinkList& rt) {
		root = new Node(value, lt.root, rt.root);
		lt.root = NULL;rt.root = NULL;
	}
	elemType getRoot() const { return root->data; }  //ȡ������ֵ
	elemType getLeft() const { return root->left->data; }  //ȡ���ӵ�ֵ
	elemType getRight() const { return root->right->data; }  //ȡ�Һ��ӵ�ֵ


};

template <class elemType>
void BinaryLinkList<elemType>::clear(Node* t)  //���
{
	if (t->left) clear(t->left);
	if (t->right) clear(t->right);
	delete t;
}

template <class elemType>
int BinaryLinkList<elemType>::size(Node* t)const //�������Ľ������
{
	if (t == NULL) return 0;  //�ݹ���ڣ����������Ϊ0
	return 1 + size(t->left) + size(t->right);  //���Ľ����Ϊ�������������+���ڵ�
}
template <class elemType>
int BinaryLinkList<elemType> ::height(Node* t)const  //�������ĸ߶�
{
	if (t == NULL) return 0;  //�ݹ����,�����߶�Ϊ0
	else {
		int lh = height(t->left), rh = height(t->right);
		return 1 + ((lh > rh) ? lh : rh);  //���ĸ߶�Ϊ���������߶ȴ���+1z
	}
}
template<class elemType>
int BinaryLinkList<elemType>::leafNum(Node* t)const //��������Ҷ����
{
	if (t==NULL)return 0;           //       �ݹ���ڣ�����Ҷ����Ϊ��                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  0;  //�ݹ���ڣ�����Ҷ����Ϊ0
	else if ((t->left == NULL) && (t->right == NULL))return 1; 
	//�ݹ���ڣ�Ҷ�ӽ�� 
	else return leafNum(t->left) + leafNum(t->right);
	//�ݹ�ͳ����������Ҷ�����ܺ�

}
template<class elemType>
void BinaryLinkList<elemType>::preOrder(Node* t)const  //ǰ�����
{
	if (t) {
		cout << t->data << ' ';  //���ʵ�ǰ���
		preOrder(t->left);  //�ݹ�ǰ�������������
		preOrder(t->right);  //�ݹ�ǰ�����������

	}
}
template <class elemType>
void BinaryLinkList<elemType>::inOrder(Node* t)const  //�������
{
	if (t) {
		inOrder(t->left);
		cout << t->data << ' ';
		inOrder(t->right);
	}
}
template<class elemType>
void BinaryLinkList<elemType>::postOrder(Node* t)const //�������
{
	if (t) {
		postOrder(t->left);
		postOrder(t->right);
		cout << t -> data << ' ';
	}
}
template<class elemType>
void BinaryLinkList<elemType>::levelOrderTraverse() const  // ��α���
{
	queue<Node*> que;  //ʹ��STL�еĶ���
	Node* p = root;
	if (p) que.push(p);  //����������
	while (!que.empty()) { //���зǿ�
		p = que.front();  // ȡ����Ԫ��
		que.pop();  //����
		cout << p->data << ' ';  //���ʵ�ǰ���
		if (p->left != NULL)que.push(p->left);  //������������
		if (p->right != NULL)que.push(p->right);  //������������


	}
}
template<class elemType>
void BinaryLinkList<elemType>::preOrderCreate(elemType flag, Node*& t)
{
	//�����ⲿ����ǰ�����й�����������ʾ�Ķ�����
	elemType value;
	cin >> value;   
	if (value != flag)//�ݹ����value==flag
	{
		t = new Node(value);
		preOrderCreate(flag, t->left); //�ݹ鴴��������
		preOrderCreate(flag, t->right);  //�ݹ鴴��������

	}
}
template<class elemType>
void BinaryLinkList<elemType>::levelOrderCreate(elemType flag)
{
	//�����ⲿ���Ĳ�����й�����������ʾ�Ķ�����
	queue<Node *> que;   //ʹ��STL�еĶ���
	Node* p;  
	elemType value, ldata, rdata;
	cin >> value;
	if (value != flag) root = new Node(value); //���������
	que.push(root);   //���
	while(!que.empty()) {  //���зǿ�
		p = que.front();  que.pop(); //ȡ����Ԫ��
		cin >> ldata >> rdata;  //�������Һ���
		if (ldata != flag)que.push(p->left = new Node(ldata));
		if (rdata != flag)que.push(p->right = new Node(rdata));

	}


}

template <class elemType>
void BinaryLinkList<elemType>::preOrderWithStack() const
{  //�ǵݹ�ǰ�����
	stack<Node*> s;  //ʹ��STL���е�ջ
	Node* p = root;  //����ָ��
	while (!s.empty() || p)  //ջ�ǿջ���p��ȫ
	{
		if (p)
		{
			s.push(p);  //ָ����ջ
			cout << p->data << ' ';  //���ʵ�ǰ���
			p = p->left;  //����ָ��ָ��������
		}
		else
		{
			p = s.top();  //��ȡջ��Ԫ��
			s.pop();  //��ջ
			p = p->right;  //����ָ��ָ��������
		}
	}

}

template <class elemType>
void BinaryLinkList<elemType>::inOrderWithStack() const
{  //�ǵݹ��������
	stack<Node*> s;  //ʹ��STL�е�ջ
	Node* p = root;  //����ָ��
	while (!s.empty() || p) {  //ջ�ǿջ���P�ǿ�
		if (p) {
			s.push(p);  //ָ����ջ
			p = p->left;  //����ָ��ֻ��������

		}
		else {  //������������ϣ���ת��������
			p = s.top();  //��ȡջ��Ԫ��
			s.pop();  //��ջ
			cout << p->data << ' ';  //���ʵ�ǰ���
			p = p->right;  //����ָ��ָ��������

		}

	}

}
template<class elemType>
void BinaryLinkList<elemType>::postOrderWithStack() const
{
	//�ǵݹ�������
	StackElement element;
	stack<StackElement> S;        
	//ʹ��STL�е�ջ
	Node* p = root;
	//����ָ��
	 while (!S.empty() || p) {
		while (p != NULL) {
			element.pointer = p;
			element.tag = Left;
			S.push(element);
			p = p->left;  //��������������������
		}
		element = S.top();  
		S.pop();//ȡջ��Ԫ��
		p = element.pointer;
		if (element.tag == Left) { //������������
			element.tag = Right;
			S.push(element);
			p = p->right;

		}
		else {  //������������
			cout << p->data << ' ';   //���ʵ�ǰ���
			p = NULL;  
		}
	}
} 
#endif