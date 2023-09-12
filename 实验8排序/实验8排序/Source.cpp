



//������
template <class Type>
void siftDown(Type R[], int pos,int size)
{
	int child;
	Type tmp = R[pos];
	for (;pos * 2 + 1 < size;pos = child)
	{
		child = pos * 2 + 1;
		if (child != size - 1 && R[child + 1] > R[child])
			child++;  //ѡȡ�������ӵĴ���
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
//���Ը���������
template<class Type>
void testSort(void(*sort)(Type R[], int size))
{
	clock_t start, finish;
	double duration;

	srand(1);  //��������������
	cout << "�����ģ:" << N << endl;
	int* array = new int[N];  //�����������,����ΪN
	//for(int i=0;i<N;i++)
	//cout<,(array[i]=rand()%(N+8))<<"\T";  //0��N-1֮��������

	for (int i = 0;i < N;i++)
		cout << (array[i] = A[i]) << "\t";
	cout << endl;

	start = clock();
	sort(array, N);  //����
	finish = clock();
	duration = (double)(finish - start);  //

	for (int i = 0;i < N;i++)
		cout << array[i] << "\t";
	cout << "�����ʱ" << duration << "ms\n";
	cout << "--------------------------\n";


}

int main()
{
	cout << "ֱ�Ӳ�������,";
	testSort(straightInsertSort<int>);
	cout << "ϣ������,";
	testSort(shellSort<int>);
	cout << "ֱ��ѡ������,";
	testSort(straightSelectSort<int>);
	cout << "������,";
	testSort(heapSort<int>);
	cout << "ð������,";
	testSort(bubbleSort<int>);
	cout << "��������,";
	testSort(quickSort<int>);
	cout << "�鲢����,";
	testSort(mergeSort<int>);
	char x;
	cin >> x;
}