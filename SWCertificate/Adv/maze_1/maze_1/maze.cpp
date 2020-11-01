#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_X	100
#define MAX_Y	100

int size_x, size_y;
char maze[MAX_Y][MAX_X];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool valid_check(int x, int y)
{
	if (x < 0 || x > size_x) return false;
	if (y < 0 || y > size_y) return false;
	if (maze[y][x] == '1') return false;
	if (maze[y][x] == '4') return false;

	return true;
}

bool find_routine(int cx, int cy)
{
	if(!valid_check(cx, cy)) return false;

	if (maze[cy][cx] == '3') return true;

	maze[cy][cx] = '4';

	for (int y = 0; y < size_y; y++)
	{
		for (int x = 0; x < size_x; x++)
		{
			cout << maze[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		if (find_routine(cx + dx[i], cy + dy[i]))
			return true;
	}

	return false;
}


int main()
{
	FILE* fp = freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	
	int T;
	int startx, starty;

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> size_x >> size_y;

		startx = starty = -1;

		for (int y = 0; y < size_y; y++)
		{
			for (int x = 0; x < size_x; x++)
			{
				cin >> maze[y][x];

				if (maze[y][x] == '2')
				{
					starty = y;
					startx = x;
				}
			}
		}
		
		if (startx == -1)
		{
			cout << "#" << tc << " IMPOSSIBLE(not found start point)" << endl;
			continue;
		}

		if (find_routine(startx, starty))
			cout << "#" << tc << " SUCCESS" << endl;
		else
			cout << "#" << tc << " IMPOSSIBLE" << endl;
	}

	return 0;
}