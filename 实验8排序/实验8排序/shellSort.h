//ϣ������
template <class Type>
void shellSort(Type R[], int size)
{
	int gap, pos, j;
	Type tmp;
	for (gap = size / 2;gap > 0;gap /= 2) {
		//gap:ϣ������,������
		for (pos = gap;pos < size;pos++) {
			//pos:�������¼λ��
			tmp = R[pos];
			for (j = pos - gap;j >= 0 && R[j] > tmp;j -= gap)
				R[j + gap] = R[j];  //��¼����
			R[j + gap] = tmp;   //���������¼������λ��
		}
	}
}
