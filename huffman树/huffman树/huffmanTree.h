#ifndef _HUFFMAN_TREE_H_
#define _HUFFMAN_TREE_H_

template <class T>
class huffmanTree {
private:
	struct Node {  
		T data;   //���������
		int weight;  //����Ȩֵ
		int parent, left, right;  //˫�׼����Һ��ӵ��±�
		Node() {
			weight = parent = left = right = 0;
		};


	};
	struct huffmanCode {
		T data;
		string code;  //����data�Ĺ������ı���
		huffmanCode() { code = ""; }  //���캯��
	};
	Node* hfTree;  //˳��ṹ������huffman��
	huffmanCode* hfCode;   //˳��ṹ������ڵ��huffman����
	int size;    //Ҷ�����
	void selectMin(int m, int& p);   //ѡ����ǰ�����е���СԪ��
public:
	huffmanTree(int initSize);  //���캯��
	~huffmanTree() { delete[] hfTree;delete[]hfCode; }  //��������
	void createHuffmanTree(const T* d, const double* w); //������������
	void huffmanEncoding();  //��ȡhuffman����
	void printHuffmanCode();  //���huffman����

};
template<class T>
huffmanTree<T> ::huffmanTree(int initSize) {  //���캯��
	size = initSize;  //sizeΪ��ʼ���еĽ����
	hfTree = new Node[2 * size];
	hfCode = new huffmanCode[size];

}
template <class T>
void huffmanTree<T>::createHuffmanTree(const T* d, const double* w) {  //������������
	int i, min1, min2;
	for (i = size;i < 2 * size;++i) {
		hfTree[i].data = d[i - size];
		hfTree[i].weight = w[i - size];
		//hfTree[i].parent = hfTree[i].right.right
	}
	for (i = size - 1;i > 0;--i) {  //���кϲ�������n-1���½��
		selectMin(i + 1, min1);  //ѡ��parent��ֵΪ0��Ȩֵ��С���������min1��min2
		hfTree[min1].parent = i;
		selectMin(i + 1, min2);
		hfTree[min2].parent = i;
		//�½��i��ֵ
		hfTree[i].weight = hfTree[min1].weight + hfTree[min2].weight;
		hfTree[i].left = min1; hfTree[i].right = min2;
		//hfTree[i].parent = 0;
	}

} 
template<class T>
void huffmanTree<T>::selectMin(int m, int& p) { //ѡ����ǰ�����е���СԪ��
	int j = m;
	while (hfTree[j].parent != 0)j++;  //��������˫�׵Ľ��
	
	for (p = j, j += 1;j < 2 * size;j++)  //���ɨ��ʣ��Ԫ��
		if ((hfTree[j].weight < hfTree[p].weight) && 0 == hfTree[j].parent)
			p = j;   //������ָ�С�ļ�¼����¼����λ��

}
template <class T>
void huffmanTree<T>::huffmanEncoding() {  //��ȡhffman����
	int f, p;
	for (int i = size;i < 2 * size;++i) {
		hfCode[i - size].data = hfTree[i].data;

		f = hfTree[i].parent;p = i;
		while (f) {
			if (hfTree[f].left == p)
				hfCode[i - size].code = '0' + hfCode[i - size].code;
			else hfCode[i - size].code = '1' + hfCode[i - size].code;
			p = f;f = hfTree[p].parent;
		}
	}

}
template<class T>
void huffmanTree<T>::printHuffmanCode() {  //���huffman����
	for (int i = 0;i < size;i++)
		cout << hfCode[i].data << ':'
		     << hfCode[i].code << endl;

}

#endif