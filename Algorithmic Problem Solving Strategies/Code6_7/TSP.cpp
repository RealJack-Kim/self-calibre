#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define	MAX_CITY	100

const double INF = 100000000.0;
double dist[MAX_CITY][MAX_CITY];
bool visited[MAX_CITY];
int path[MAX_CITY];
int numCity;

double min_xy(double x, double y)
{
	return x > y ? y : x;
}

double shortestPath(int pathLength, double currentLength)
{
	if (pathLength == (numCity - 1))
	{
		double tmp_result = currentLength + dist[path[0]][path[pathLength]];
/*
		cout << path[0];
		for (int i = 1; i < numCity; i++)
		{
			cout << " > " << path[i];
		}
		cout << " : " << tmp_result << endl;
*/
		return tmp_result;
	}

	double ret = INF;

	for (int next = 0; next < numCity; next++)
	{
		if (visited[next])
			continue;

		int here = path[pathLength];
		path[pathLength + 1] = next;
		visited[next] = true;

		double cand = shortestPath(pathLength + 1, currentLength + dist[here][next]);
		ret = min_xy(ret, cand);

		visited[next] = false;
	}

	return ret;
}


int main()
{
	FILE* fp = freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		memset(visited, 0, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		memset(path, 0, sizeof(path));

		cin >> numCity;

		for(int i = 0; i < numCity; i++)
			for (int j = i + 1; j < numCity; j++)
			{
				cin >> dist[i][j];
				dist[j][i] = dist[i][j];
			}

		visited[0] = true;
		double result = shortestPath(0, 0.0);
		cout << "#" << tc + 1 << " " << result << endl;
	}

	return 0;
}
