//ֱ�Ӳ���˳��
template<class Type>
void straightInsertSort(Type R[], int size)
{
	int pos, j;  //pos:�������¼λ��
	Type tmp;
	cout << "insert sort:\n";
	for (pos = 1;pos < size;pos++) {
		tmp = R[pos];  //���������¼�Ž���ʱ����
		//�Ӻ�����ǰ���Ҳ���λ��,�����ڴ������¼����ƶ�
		for (j = pos - 1;tmp < R[j] && j >= 0;j--)
			R[j + 1] = R[j];  //��¼����
		R[j + 1] = tmp;
	}
}
template<class Type>
void binaryInsertSort(Type R[], int size) {
	int pos, j, low, high, mid;
	Type tmp;
	cout << "binary insert sort:\n";
	for (pos = 1;pos < size;pos++) {
		//�ٶ���һ����¼����
		tmp = R[pos];  //�����ż�¼R[pos]�ݴ浽tmp
		low = 0;high = pos - 1;  //�����۲��ҵķ�Χ
		while (low <= high) {
			//��R[Low..high]���۰�����������λ��

			mid = (low + high) / 2;  //�۰�
			if (tmp < R[mid])high = mid - 1;  //������ڵͰ���
			else low = mid + 1;   //������ڸ߰���
		}
		for (j = pos - 1;j >= low;j--)
			R[j + 1] = R[j];   //��¼����
		R[low] = tmp;   //����
	}

}

