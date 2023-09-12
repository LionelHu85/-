#ifndef _BTNARY_TREE_H_
#define _BINARY_TREE_H_

template <class elemType>  //��������Ԫ������Ϊelemtype
class binaryTree {     //�������ĳ�����������
public:              
	virtual int height() const = 0;  //�������ĸ߶�
	virtual int size() const = 0;   //�������Ľ������
	virtual void clear() = 0;  //���
	virtual bool empty() const = 0;   //�п�
	virtual void preOrderTraverse() const = 0;//ǰ�����
	virtual void inOrderTraverse() const = 0;  //�������
	virtual void postOrderTraverse() const = 0;  //�������
	virtual void levelOrderTraverse() const = 0;  //��α���
	virtual ~binaryTree() {};

};

#endif
