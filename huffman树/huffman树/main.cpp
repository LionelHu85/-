#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
#include"huffmanTree.h"
int main() {
	char d[] = "GOATTTE";
	double w[] = { 9,6,5,2,3,1,7 };
	huffmanTree<char>tree(7);
	tree.createHuffmanTree(d, w);  //������������
	tree.huffmanEncoding();  //��ȡhuffman����
	tree.printHuffmanCode();  //���huffman����

	system("pause");
	return 0;
}