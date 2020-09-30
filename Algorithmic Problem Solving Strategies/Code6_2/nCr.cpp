#include <iostream>
#include <vector>
using namespace std;

void printPicked(vector <int>& picked)
{
	for (vector <int>::iterator iter = picked.begin(); iter != picked.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}

void pick(int n, vector<int>& picked, int toPick)
{
	// Base Condition
	if (toPick == 0)
	{
		printPicked(picked);
		return;
	}
	// find smallest number that can be sellected
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; next++)
	{
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

/*
void main()
{
	vector<int> element;
	int n, r;

	cout << "n = ? ";
	cin >> n;
	cout << "r = ? ";
	cin >> r;

	pick(n, element, r);
}
*/