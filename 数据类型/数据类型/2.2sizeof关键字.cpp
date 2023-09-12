#include<iostream>
using namespace std;

int main() {

    //整型： short （2） int (4) long(4)  long long （8）
    //可以利用sizeof求出数据类型占用内存大小
    //语法： sizeof（数据类型/变量 )
    short num1 = 10;
        cout << "shrot占用内存空间为:" << sizeof(short) << endl;
    system("pause");

    //整型大小比较
    //short< int< = long 
    return 0;
}