#include<iostream>
using namespace std;
int main() {

	/*int a1 = 10;
	int b1 = 3;
	cout << a1 % b1 << endl;
	//取模运算的本质就是求余数

	int a2 = 10;
	int b2 = 20;
	cout << a2 % b2 << endl;*/

	//取模运算时，除数也不能为0
	//两个小数不可以取模

	//1、前置递增，
	int a = 10;
	++a; //让变量+1
	cout << "a =" << a << endl;



	//2、后置递增
	int b = 10;
	b++; //变量进行+1
	cout << "b = " <<b << endl;



	//3.前置和后置递增
	//前置递增 先让变量+1 然后进行表达式运算
	int a2 = 10;
	int b2 = ++a2 * 10;
	cout << "a2 = " << a2 << endl;
	cout << "b2=" << b2 << endl;


	//后置递增 先进行表达式运算，后让变量+1；


	int a3 = 10;
	int b3 = a3++ * 10;
	cout << "a3 = " << a3 << endl;
	cout << "b3 = " << b3 << endl;



	system("pause");
	return 0;
}