#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 스티커

#include <stdio.h>
#define MAX_N	100000
int dp[3][MAX_N + 1];
int score[3][MAX_N + 1];

int max_xy(int x, int y)
{
	return (x > y ? x : y);
}

int main(void)
{
	int T, n, max_result;
	
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &n);

		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &score[i][j]);
			}

		for (int i = 1; i <= n; i++)
		{
			dp[0][i] = max_xy(dp[1][i - 1], dp[2][i - 1]);
			dp[1][i] = max_xy(dp[0][i - 1], dp[2][i - 1]) + score[1][i];
			dp[2][i] = max_xy(dp[0][i - 1], dp[1][i - 1]) + score[2][i];
		}

		max_result = max_xy(dp[0][n], dp[1][n]);
		max_result = max_xy(max_result, dp[2][n]);

		printf("%d\n", max_result);
	}
	return 0;
}