#include <iostream>
#include <cstdlib>
#include <bits.h>
#include <iomanip>
#include "RationalNumber.h"
using namespace std;


int gcd(int shang, int xia) {
	int r;
	while (xia > 0) {
		r = shang % xia;
		shang = xia;
		xia = r;
	}
	return shang;
}

int main() {

	cout << "欢迎使用分数计算器" << endl;
	while (1)
	{
		int shang, xia,c;  //分子分母
		cout << endl;

		cout << "请输入第一个分数：" << endl;
		
		cin >> shang >> xia;
		if (shang == 0) {   //分子为0，直接输出0；
			cout << shang << endl;
			return 0;
		}
		c = gcd(shang, xia);//得到最大公约数
		shang = shang / c;
		xia = xia / c;
		if (xia == 1) {   //b==1时，该分数为整数，直接输出分子a
			cout << shang << endl;
		}
		else {
			if (shang > xia) {  //a>b时，该分数为假分数
				cout << shang / xia << "+" << shang % xia << "/" << xia << endl;
			}
			else {    //a<b时，该分数为真分数
				cout << shang << "/" << xia << endl;
			}
		while (1)
		{
			cin >> shang;
			getchar();        //“/”符号
			cin >> xia;

			try
			{
				if (xia == 0)
				{
					throw - 1;   //抛出int类型异常
				}
				else
				{
					cout << "该分数为：" << endl;
					break;
				}
			}
			catch (int)
			{
				cout << "分母不能为0，请重新输入" << endl;//异常处理
				cout << endl;
			}

		}
		RationalNumber a(shang, xia);          //将分子分母存储为RationalNumber类
		a.printRational();
		cout << endl;
		cout << endl;
		RationalNumber x;
		int select;
		while (1)
		{
			system("pause");
			system("cls");

			cout << setw(20) << "===============" << endl;
			cout << setw(20) << "1.加法运算" << endl;
			cout << setw(20) << "2.减法运算" << endl;
			cout << setw(20) << "3.乘法运算" << endl;
			cout << setw(20) << "4.除法运算" << endl;
			cout << setw(20) << "5.关系判别" << endl;
			cout << setw(20) << "6.重新输入" << endl;
			cout << setw(20) << "0.退出" << endl;
			cout << setw(20) << "============" << endl;
			cout << setw(20) << "请输入菜单项" << endl;
			cin >> select;

			if (select == 6)
				break;
			if (select == 0)
				return 0;

			cout << endl;
			cout << "请输入第二个分数：" << endl;
			while (1)
			{
				cin >> shang;
				getchar();
				cin >> xia;
				try
				{
					if (xia == 0)
					{
						throw - 1;  ///抛出int类型异常

					}
					else
					{
						cout << "该分数为：" << endl;
						break;
					}
				}
				catch (int)
				{
					cout << "分母不能为0，请重新输入" << endl;

				}
			}
			RationalNumber b(shang, xia);
			b.printRational();

			cout << endl;
			switch (select)
			{
			case 1:
				x = a + b;
				cout << endl;
				cout << "相加结果为：";
				a.printRational();
				cout << "+";
				b.printRational();
				cout << "=";
				x.printRational();
				a = x;
				cout << endl;
				cout << endl;
				break;
			case 2:
				x = a - b;
				cout << endl;
				cout << "相减结果为：";
				a.printRational();
				cout << "-";
				b.printRational();
				cout << "=";
				x.printRational();
				cout << endl;
				break;
			case 3:
				x = a * b;
				cout << endl;
				cout << "相乘结果为：";
				a.printRational();
				cout << "*";
				b.printRational();
				cout << "=";
				x.printRational();
				a = x;
				cout << endl;
				cout << endl;
				break;
			case 4:
				x = a / b;
				cout << endl;
				cout << "相除结果为：";
				a.printRational();
				cout << "/";
				b.printRational();
				a = x;
				cout << endl;
				cout << endl;
				break;
			case 5:
				cout << endl;
				cout << "判断结果为：";
				cout << endl;
				a.printRational();
				cout << ((a > b) ? ">" : "<=");
				b.printRational();
				cout << endl;
				a.printRational();
				cout << ((a != b) ? "!=" : "==");
				b.printRational();
				cout << endl;
				cout << endl;
				break;
			case 6:
				break;
			case 0:
				return 0;
			}
		}
	}

}