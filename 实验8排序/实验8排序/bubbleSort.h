//ð������
template<class Type>
void bubbleSort(Type R[], int size)
{
	int i, j;
	bool flag = true;   //��¼һ��������Ƿ���������
	for (i = 1;i < size && flag;++i) {
		flag = false;  //�ٶ���������û�н���
		for (j = 0;j < size - i;++j)
			if (R[j + 1] < R[j]) {
				//����
				swap(R[j], R[j + 1]);  //������tmp = R[j];R[j]
				flag = true;
			}
	}
}
