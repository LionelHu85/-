



//堆排序
template <class Type>
void siftDown(Type R[], int pos,int size)
{
	int child;
	Type tmp = R[pos];
	for (;pos * 2 + 1 < size;pos = child)
	{
		child = pos * 2 + 1;
		if (child != size - 1 && R[child + 1] > R[child])
			child++;  //选取两个孩子的大者
		if (R[child] > tmp) R[pos] = R[child];
		else break;
	}
	R[pos] = tmp;
}








#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<cmath>
#include<algorithm>
using namespace std;
#include"heapSort.h"
#include"shellSort.h"
#include"straightInsertSort.h"
#include"straightSelectSort.h"
#include"bubbleSort.h"
#include"quickSort.h"
#include"mergeSort.h"
#define N 8
int A[N] = { 236,180,366,145,22,9,416,636 };
//测试各种排序函数
template<class Type>
void testSort(void(*sort)(Type R[], int size))
{
	clock_t start, finish;
	double duration;

	srand(1);  //设计随机函数种子
	cout << "数组规模:" << N << endl;
	int* array = new int[N];  //产生随机数组,长度为N
	//for(int i=0;i<N;i++)
	//cout<,(array[i]=rand()%(N+8))<<"\T";  //0到N-1之间地随机数

	for (int i = 0;i < N;i++)
		cout << (array[i] = A[i]) << "\t";
	cout << endl;

	start = clock();
	sort(array, N);  //排序
	finish = clock();
	duration = (double)(finish - start);  //

	for (int i = 0;i < N;i++)
		cout << array[i] << "\t";
	cout << "排序耗时" << duration << "ms\n";
	cout << "--------------------------\n";


}

int main()
{
	cout << "直接插入排序,";
	testSort(straightInsertSort<int>);
	cout << "希尔排序,";
	testSort(shellSort<int>);
	cout << "直接选择排序,";
	testSort(straightSelectSort<int>);
	cout << "堆排序,";
	testSort(heapSort<int>);
	cout << "冒泡排序,";
	testSort(bubbleSort<int>);
	cout << "快速排序,";
	testSort(quickSort<int>);
	cout << "归并排序,";
	testSort(mergeSort<int>);
	char x;
	cin >> x;
}