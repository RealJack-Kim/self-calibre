#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <cstdio>
using namespace std;

#define MAX_NUM	100

int data_arr[MAX_NUM];


void swap_xy(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void quick_sort(int *data_a, int start, int end)
{
	if (start >= end)
		return;

	int pivot = data_a[start];
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		while (data_a[left] < pivot)
		{
			left++;
			if (left > end)
				break;
		}
		while (data_a[right] > pivot)
			right--;

		if (left <= right)
		{
			swap_xy(&data_a[left], &data_a[right]);
			left++;
			right--;
		}
	}

	swap_xy(&data_a[start], &data_a[right]);
	quick_sort(data_a, start, right - 1);
	quick_sort(data_a, right + 1, end);
}

int main()
{
	FILE* fp = freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;

	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> data_arr[i];
			cout << data_arr[i] << " ";
		}
		cout << endl;

		quick_sort(data_arr, 0, n - 1);

		cout << "result : ";
		for (int i = 0; i < n; i++)
			cout << data_arr[i] << " ";
		cout << endl;
	}

	return 0;
}