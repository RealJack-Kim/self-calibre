#include <iostream>
using namespace std;

#define MAX_SIZE	100

int index_arr[MAX_SIZE + 1];

int count_num;

void printPicked2(int set_size)
{
	for (int i = 0; i < set_size; i++)
		cout << index_arr[i] << " ";
	cout << endl;
}

void pick2(int set_size, int n, int r)
{
	if (set_size == r)
	{
		count_num++;
		printPicked2(set_size);
		return;
	}

	int start = set_size == 0 ? 0 : index_arr[set_size - 1] + 1;

	for (int next = start; next < n; next++)
	{
		index_arr[set_size] = next;
		pick2(set_size + 1, n, r);
	}
}

void main()
{
	
	int n, r;

	cout << "n = ? ";
	cin >> n;
	cout << "r = ? ";
	cin >> r;

	count_num = 0;
	pick2(0, n, r);
	cout << count_num << endl;
}