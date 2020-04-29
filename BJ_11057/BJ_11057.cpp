#include <stdio.h>
#define MAX_N	1000

int dp[MAX_N + 1][10];

int main(void)
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i][9] = dp[i - 1][9];
		for (int j = 8; j <= 0; j--)
			dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
	}

	return 0;
}