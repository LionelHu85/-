//���ô���ѣ�������R��ǰ����size��Ԫ������
template <class Type>
void heapSort(Type R[], int size)
{
	int i;
	//Type tmp;
	//������ʼ��,����siftDown(R,i,size)����Ϊ�����
	for (i = size / 2 - 1;i >= 0;i--)  //�����һ����Ҷ�ڵ㿪ʼ
		siftDown(R, i, size);
	for (i = size - 1;i > 0;i--) {
		//size-1�γ��ӣ���������
		swap(R[0], R[i]);   //������tmp = R[0]
		siftDown(R, 0, 1);  //�Զ����µ���

	}
}
