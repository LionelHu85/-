//利用大根堆，对数组R的前几个size个元素排序
template <class Type>
void heapSort(Type R[], int size)
{
	int i;
	//Type tmp;
	//创建初始堆,调用siftDown(R,i,size)调整为大根堆
	for (i = size / 2 - 1;i >= 0;i--)  //从最后一个非叶节点开始
		siftDown(R, i, size);
	for (i = size - 1;i > 0;i--) {
		//size-1次出队，即（队首
		swap(R[0], R[i]);   //交换：tmp = R[0]
		siftDown(R, 0, 1);  //自顶向下调整

	}
}
