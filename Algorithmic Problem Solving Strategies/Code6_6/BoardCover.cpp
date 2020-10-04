#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_X	20
#define MAX_Y	20

const int coverType[4][3][2] = {
	{{0, 0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
};

int board[MAX_X][MAX_Y];
int H, W;

void print_board(void)
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

bool set(int x, int y, int type, int delta)
{
	bool ret = true;

	for (int i = 0; i < 3; i++)
	{
		const int nx = x + coverType[type][i][0];
		const int ny = y + coverType[type][i][1];

		if (nx < 0 || nx >= H || ny < 0 || ny >= W)
			ret = false;
		else if ((board[nx][ny] += delta) > 1)
			ret = false;
	}
/*
	if (ret == true)
		print_board();
	else
		cout << "NOOP!!" << endl;
	cout << endl;
*/

	return ret;
}

int cover(int last_x)
{
	int x = -1, y = -1;

	for (int i = last_x; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (board[i][j] == 0)
			{
				x = i;
				y = j;
				break;
			}
		}
		if (x != -1)
			break;
	}

	if (x == -1)
		return 1;

	int ret = 0;
	for (int type = 0; type < 4; type++)
	{
		if (set(x, y, type, 1))
		{
			ret += cover(x);
		}
		set(x, y, type, -1);
	}

	return ret;
}


int main()
{
	FILE* fp = freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;
	char ch;

	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> H >> W;

		for(int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				cin >> ch;
				if (ch == '#')
					board[i][j] = 1;
				else if (ch == '.')
					board[i][j] = 0;
				else if (ch == '\n')
					cout << "endl" << endl;
				else
					cout << "Input ERROR" << endl;
			}

		int result = cover(0);
		cout << "#" << tc+1 << " " << result << endl;
	}

	return 0;
}