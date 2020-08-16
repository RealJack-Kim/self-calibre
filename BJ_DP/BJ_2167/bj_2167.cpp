#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 2차원 배열의 합

#include <stdio.h>
#define MAX_NM	300
#define MAX_K	10000

int dp[MAX_NM + 1][MAX_NM + 1], A[MAX_NM + 1][MAX_NM + 1];
int result[MAX_K + 1];

int main(void)
{
	int N, M, K;
	int k, i, j, x, y;

	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			scanf("%d", &A[i][j]);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + A[i][j] - dp[i - 1][j - 1];
		}
	}

	scanf("%d", &K);
	for (k = 1; k <= K; k++)
	{
		scanf("%d %d %d %d", &i, &j, &x, &y);
		result[k] = dp[x][y] - dp[i - 1][y] - dp[x][j - 1] + dp[i - 1][j - 1];
	}

	for (k = 1; k <= K; k++)
		printf("%d\n", result[k]);

	return 0;
}