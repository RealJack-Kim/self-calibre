#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <iostream>
using namespace std;

#define	MAX_CITY	100

const double INF = 100000000.0;
double dist[MAX_CITY][MAX_CITY];
bool visited[MAX_CITY];
int path[MAX_CITY];
int numCity;

double shortestPath(int pathLength, double currentLength)
{
	if (pathLength == numCity)
		return currentLength + dist[path[0]][path[pathLength - 1]];

	double ret = INF;

	for (int next = 0; next < numCity; next++)
	{
		if (visited[next])
			continue;

		int here = path[pathLength - 1]];
	}
}


int main()
{
	FILE* fp = freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		cin >> numCity;

	}

	return 0;
}
