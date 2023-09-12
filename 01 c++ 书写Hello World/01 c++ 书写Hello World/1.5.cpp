# include <iostream>
using namespace std;

int main()
{
	//1.标识符不可以是关键字
//2.标识符是由字母、数字、下划线构成
	//3.标识符第一个字符只能是字母或下划线
	//4.标识符区分大小写
	//int aaa = 100;
	//cout << aaa << endl;
	//cout << AAA << endl1;  ///AAA 和 aaa 不是同一个名称
	
	//建议：给变量起名时，最好能够做到见名如意
	int num1 = 10;
	int num2 = 20;
	int sum = num1 + num2;
	cout << sum << endl;
     system("pause");
	return 0;
}