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

	cout << "��ӭʹ�÷���������" << endl;
	while (1)
	{
		int shang, xia,c;  //���ӷ�ĸ
		cout << endl;

		cout << "�������һ��������" << endl;
		
		cin >> shang >> xia;
		if (shang == 0) {   //����Ϊ0��ֱ�����0��
			cout << shang << endl;
			return 0;
		}
		c = gcd(shang, xia);//�õ����Լ��
		shang = shang / c;
		xia = xia / c;
		if (xia == 1) {   //b==1ʱ���÷���Ϊ������ֱ���������a
			cout << shang << endl;
		}
		else {
			if (shang > xia) {  //a>bʱ���÷���Ϊ�ٷ���
				cout << shang / xia << "+" << shang % xia << "/" << xia << endl;
			}
			else {    //a<bʱ���÷���Ϊ�����
				cout << shang << "/" << xia << endl;
			}
		while (1)
		{
			cin >> shang;
			getchar();        //��/������
			cin >> xia;

			try
			{
				if (xia == 0)
				{
					throw - 1;   //�׳�int�����쳣
				}
				else
				{
					cout << "�÷���Ϊ��" << endl;
					break;
				}
			}
			catch (int)
			{
				cout << "��ĸ����Ϊ0������������" << endl;//�쳣����
				cout << endl;
			}

		}
		RationalNumber a(shang, xia);          //�����ӷ�ĸ�洢ΪRationalNumber��
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
			cout << setw(20) << "1.�ӷ�����" << endl;
			cout << setw(20) << "2.��������" << endl;
			cout << setw(20) << "3.�˷�����" << endl;
			cout << setw(20) << "4.��������" << endl;
			cout << setw(20) << "5.��ϵ�б�" << endl;
			cout << setw(20) << "6.��������" << endl;
			cout << setw(20) << "0.�˳�" << endl;
			cout << setw(20) << "============" << endl;
			cout << setw(20) << "������˵���" << endl;
			cin >> select;

			if (select == 6)
				break;
			if (select == 0)
				return 0;

			cout << endl;
			cout << "������ڶ���������" << endl;
			while (1)
			{
				cin >> shang;
				getchar();
				cin >> xia;
				try
				{
					if (xia == 0)
					{
						throw - 1;  ///�׳�int�����쳣

					}
					else
					{
						cout << "�÷���Ϊ��" << endl;
						break;
					}
				}
				catch (int)
				{
					cout << "��ĸ����Ϊ0������������" << endl;

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
				cout << "��ӽ��Ϊ��";
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
				cout << "������Ϊ��";
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
				cout << "��˽��Ϊ��";
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
				cout << "������Ϊ��";
				a.printRational();
				cout << "/";
				b.printRational();
				a = x;
				cout << endl;
				cout << endl;
				break;
			case 5:
				cout << endl;
				cout << "�жϽ��Ϊ��";
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