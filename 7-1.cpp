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
		//从后往前找小数，定j
		while (arr[j] >= temp && j > i) {
			j--;
		}
		//从前往后找大数，定i
		while (arr[i] <= temp && j > i) {
			i++;
		}
		//进行调位判断
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

	//输入
	int n;
	cin >> n;
	int A[100];
	int i;
	int flag = 0;
	for (i = 1; i <= n; i++) {
		cin >>  A[i];
	}
	//调用快排函数
	quickSort(A, 1, n, 0);
	
	//输出
	for (i = 1; i <= n; i++) {
		cout << A[i] << ' ';
	}

	return 0;
}
