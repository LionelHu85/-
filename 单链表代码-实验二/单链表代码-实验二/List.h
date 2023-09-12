#ifndef _LIST_H_
#define _LIST_H_
using namespace std;
class outOfRange{};
class badSize{};
template<class T>
class List
{
public:
	virtual void clear() = 0;  //������Ա�
	virtual bool empty()const = 0; // �пգ��ձ���true���ǿշ���false
	virtual int size()const = 0; //�����Ա�ĳ���
	virtual void insert(int i, const T& value) = 0; // �����Ա��У�λ��Ϊi[0..n]��λ�ò���Ԫ��value
	virtual void remove(int i) = 0; //�����Ա��У�λ��Ϊi[0..n-1]��λ��ɾ��Ԫ��
	virtual int search(const T& value)const = 0;  //�����Ա�����ֵΪvalue��Ԫ�ص�һ�γ��ֵ�λ��
	virtual void traverse()const = 0;  //�������Ա�
	virtual void inverse() = 0;  //�������Ա�
	virtual ~List() {};

};

#endif
