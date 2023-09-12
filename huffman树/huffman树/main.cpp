#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
#include"huffmanTree.h"
int main() {
	char d[] = "GOATTTE";
	double w[] = { 9,6,5,2,3,1,7 };
	huffmanTree<char>tree(7);
	tree.createHuffmanTree(d, w);  //创建哈夫曼树
	tree.huffmanEncoding();  //获取huffman编码
	tree.printHuffmanCode();  //输出huffman编码

	system("pause");
	return 0;
}