//��������
template <class Type>
int partition(Type S[], int low, int high) {
	Type tmp = S[low];  //�ݴ���ֵ
	while (low != high) {
		//��ʼ���зָ�
		while (low < high && S[high] >= tmp)high--; //���±����<��ֵ�ؼ�¼
		if (low < high) { S[low] = S[high];low++; }  //�ü�¼�ƶ���С�±��
		while (low < high && S[low] <= tmp)low++;  //С�±����>��ֵ�ļ�¼
		if (low < high) { S[high] = S[low];high--; }  //�ü�¼�ƶ������±��

	}
	S[low] = tmp;  //����ֵ����ֽ�λ����
	return low;  //������ֵλ��

}
template <class Type>
void quickSort(Type S[], int low, int high) {
	int pivot;
	if (low >= high)return;
	pivot = partition(S, low, high);  //һ�ηֻ�����������λ��

	quickSort(S, low, pivot - 1);  //���������һ���������
	quickSort(S, pivot + 1, high);  //�������ұ�һ���������

}
template<class Type>
void quickSort(Type S[], int size) {
	quickSort(S, 0, size - 1);
}
template<class Type>
void findJ(Type A[], int n, int j) {
	int i = partition(A, 1, n);
	while (i != j)
		if (i < j) i = partition(A, i + 1, n);  //�ں�벿�ּ������л���
		else i = partition(A, 1, i - 1);//��ǰ�벿�ּ������л�����
	cout << A[i] << endl;
}
