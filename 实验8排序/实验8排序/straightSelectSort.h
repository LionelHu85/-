//ֱ��ѡ������
template <class Type>
void straightSelectSort(Type R[], int size)
{
	int pos, min, j;  //min:һ��ѡ������СԪ���±�
	cout << "select sort:\n";
	for (pos = 0;pos < size - 1;pos++) {//pos:�������С��¼λ��
		min = pos;
		for (j = pos + 1;j < size;++j)
			if (R[j] < R[min])min = j;  //������С��¼
		if (pos != min)swap(R[pos], R[min]);  //������tmp
	}

}

