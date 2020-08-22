#include <iostream>
using namespace std;

// #define PRINT_RESULT

#define MAX_SIZE	100

int result[MAX_SIZE];
int data_d[MAX_SIZE];
int index_arr[MAX_SIZE];
int num_count;

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int permutation(int n, int r, int index)
{
	// 종료 조건
	if (index == r)
	{
		num_count++;
#ifdef PRINT_RESULT
		for (int i = 0; i < r; i++)
		{
			cout << data_d[i] << " ";
		}
		cout << endl;
#endif
		return 0;
	}
	
	// 재귀 부분
	for (int i = index; i < n; i++)
	{
		swap(&data_d[index], &data_d[i]);
		permutation(n, r, index + 1);
		swap(&data_d[index], &data_d[i]);
	}

	return 0;
}

int repeated_permutation(int n, int r, int index)
{
	// 종료 조건
	if (index == r)
	{
		num_count++;
#ifdef PRINT_RESULT
		for (int i = 0; i < r; i++)
		{
			cout << data_d[index_arr[i]] << " ";
		}
		cout << endl;
#endif		
		return 0;
	}

	// 재귀 부분
	for (int i = 0; i < n; i++)
	{
		index_arr[index] = i;
		repeated_permutation(n, r, index + 1);
	}

	return 0;
}

int combination(int set_size, int n, int r, int index)
{
	// End condition
	if (set_size == r)
	{
		num_count++;
#ifdef PRINT_RESULT
		for (int i = 0; i < r; i++)
		{
			cout << data_d[index_arr[i]] << " ";
		}
		cout << endl;
#endif
		return 0;
	}

	if (index == n)
		return 0;

	// Recursive condition
	index_arr[set_size] = index;
	combination(set_size + 1, n, r, index + 1);
	combination(set_size, n, r, index + 1);

	return 0;
}

int repeated_combination(int set_size, int n, int r, int index)
{
	// End conditions
	if (set_size == r)
	{
		num_count++;
#ifdef PRINT_RESULT
		for (int i = 0; i < r; i++)
		{
			cout << data_d[index_arr[i]] << " ";
		}
		cout << endl;
#endif
		return 0;
	}

	if (index == n)
		return 0;

	// Recursive conditions
	index_arr[set_size] = index;
	repeated_combination(set_size + 1, n, r, index);
	repeated_combination(set_size, n, r, index + 1);

	return 0;
}

int main(void)
{
	// input data 
	int n, r;

	cout << "n=? ";
	cin >> n;
	cout << "r=? ";
	cin >> r;

	cout << "Input Data : ";
	for (int i = 0; i < n; i++)
	{
		cin >> data_d[i];
	}

	num_count = 0;
#ifdef PRINT_RESULT
	cout << "--------------------" << endl;
#endif
	permutation(n, r, 0);
#ifdef PRINT_RESULT
	cout << "--------------------" << endl;
#endif
	cout << n << " P " << r << " = " << num_count << endl << endl;

	num_count = 0;
#ifdef PRINT_RESULT
	cout << "--------------------" << endl;
#endif
	repeated_permutation(n, r, 0);
#ifdef PRINT_RESULT
	cout << "--------------------" << endl;
#endif
	cout << n << " ∏ " << r << " = " << num_count << endl << endl;

	num_count = 0;
#ifdef PRINT_RESULT
	cout << "--------------------" << endl;
#endif
	combination(0, n, r, 0);
#ifdef PRINT_RESULT
	cout << "--------------------" << endl;
#endif
	cout << n << " C " << r << " = " << num_count << endl << endl;

	num_count = 0;
#ifdef PRINT_RESULT
	cout << "--------------------" << endl;
#endif
	repeated_combination(0, n, r, 0);
#ifdef PRINT_RESULT
	cout << "--------------------" << endl;
#endif
	cout << n << " H " << r << " = " << num_count << endl << endl;

	return 0;
}