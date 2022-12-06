#include <iostream>
#define MAXSIZE 100;
using namespace std;

void quickSort(int* arr, int begin, int end, int flag) {
	if (begin > end) {
		return;
	}
	int temp = arr[begin];
	int i = begin;
	int j = end;
	while (i != j) {
		//�Ӻ���ǰ��С������j
		while (arr[j] >= temp && j > i) {
			j--;
		}
		//��ǰ�����Ҵ�������i
		while (arr[i] <= temp && j > i) {
			i++;
		}
		//���е�λ�ж�
		if (j > i) {
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	if (flag == 0)
		cout << i << ' ';
	arr[begin] = arr[i];
	arr[i] = temp;
	quickSort(arr, begin, i - 1, 1);
	quickSort(arr, i + 1, end, 1);
}

int main() {

	//����
	int n;
	cin >> n;
	int A[100];
	int i;
	int flag = 0;
	for (i = 1; i <= n; i++) {
		cin >>  A[i];
	}
	//���ÿ��ź���
	quickSort(A, 1, n, 0);
	
	//���
	for (i = 1; i <= n; i++) {
		cout << A[i] << ' ';
	}

	return 0;
}
