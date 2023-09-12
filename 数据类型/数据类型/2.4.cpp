#include<iostream>
using namespace std;
 
int main() {
	//1、字符型变量的创建方式
	char ch = 'a';
	cout << ch<< endl;
	//2、字符型变量所占内存大小
	cout << "char字符型变量所占内存；" << sizeof(char) << endl;
	//3、字符型变量常见错误
	
	//4、字符型变量对应ASCII编码(十进制)
	cout << (int)ch << endl;


	system("pause");
}