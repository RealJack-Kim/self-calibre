#include <iostream>
using namespace std;

#define MAX_WORD	10
#define MAX_LENGTH	100
#define MAX_X	5
#define MAX_Y	5

const int dx[8] = {-1,  0,  1, 1, 1, 0, -1, -1};
const int dy[8] = {-1, -1, -1, 0, 1, 1,  1,  0};

const char board[MAX_X][MAX_Y] = {
{ 'U', 'R', 'L', 'P', 'M' },
{ 'X', 'P', 'R', 'E', 'T' },
{ 'G', 'I', 'A', 'E', 'T' },
{ 'X', 'T', 'N', 'Z', 'Y' },
{ 'X', 'O', 'Q', 'R', 'S' } };

bool inRange(int x, int y)
{
	if (x < 0 || x >= MAX_X || y < 0 || y >= MAX_Y)
		return false;
	return true;
}

bool hasWord(int x, int y, char* wp)
{
	// Base condition 1 : Check in-Range
	if (!inRange(x, y))
		return false;

	// Base condition 2 : Check charactor in word
	if (board[x][y] != *wp)
		return false;

	// Base condition 3 : complete to find the word
	if (strlen(wp) == 1)
		return true;

	// Recusive condition
	for (int dir = 0; dir < 8; dir++)
	{
		int next_x = x + dx[dir];
		int next_y = y + dy[dir];
		if (hasWord(next_x, next_y, wp+1))
			return true;
	}

	return false;
}

int main()
{
	char word[MAX_WORD][MAX_LENGTH];
	int n;
	bool found_flag;

	cout << "n = ? ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "#" << i+1 << " Word = ? ";
		cin >> word[i];
	}

	for (int i = 0; i < n; i++)
	{
		found_flag = false;
		for (int j = 0; j < MAX_X; j++)
		{
			for (int k = 0; k < MAX_Y; k++)
			{
				if (board[j][k] == word[i][0])
				{
					if (hasWord(j, k, word[i]))
						found_flag = true;
				}
				if (found_flag)
					break;
			}
			if (found_flag)
				break;
		}
		if (found_flag)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;
	}

	return 0;
}
