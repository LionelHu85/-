#include<iostream>
using namespace std;
 
int main() {
	//1���ַ��ͱ����Ĵ�����ʽ
	char ch = 'a';
	cout << ch<< endl;
	//2���ַ��ͱ�����ռ�ڴ��С
	cout << "char�ַ��ͱ�����ռ�ڴ棻" << sizeof(char) << endl;
	//3���ַ��ͱ�����������
	
	//4���ַ��ͱ�����ӦASCII����(ʮ����)
	cout << (int)ch << endl;


	system("pause");
}