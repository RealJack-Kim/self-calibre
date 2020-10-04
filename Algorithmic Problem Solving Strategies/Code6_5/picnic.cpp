#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX_STUDENT	10

bool areFriend[MAX_STUDENT][MAX_STUDENT];
bool taken[MAX_STUDENT];

int countPairing(int n)
{
	// Base condition : find free first one having the smallest number.
	int firstFree = -1;
	for (int i = 0; i < n; i++)
	{
		if (!taken[i])
		{
			firstFree = i;
			break;
		}
	}
	// Base condition 2 : End condition
	if (firstFree == -1)
		return 1;

	// Recusive condition
	int ret = 0;

	for (int pairWith = firstFree + 1; pairWith < n; pairWith++)
	{
		if (!taken[pairWith] && areFriend[firstFree][pairWith])
		{
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairing(n);
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret;
}

int main()
{
	int T;

	FILE* fp = freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	// cout << "num of TestCase : ";
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		int n, pairnum;

		// cout << "num of student & pair : ";
		cin >> n >> pairnum;

		memset(areFriend, false, sizeof(areFriend));
		// cout << "input pair : ";
		for (int i = 0; i < pairnum; i++)
		{
			int x, y;
			cin >> x >> y;
			areFriend[x][y] = areFriend[y][x] = true;
		}

		cout << "#" << tc << " " << countPairing(n) << endl;
	}

	return 0;
}