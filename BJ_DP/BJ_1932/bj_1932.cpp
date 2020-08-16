#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 정수 삼각형
#include <stdio.h>
#define MAX_N	500

int dp[MAX_N + 1][MAX_N + 1];
int value[MAX_N + 1][MAX_N + 1];

int max(int x, int y)
{
	return (x > y ? x : y);
}
int main(void)
{
	int N, maxV;
	int i, j;

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		for (j = 1; j <= i; j++)
			scanf("%d", &value[i][j]);

	dp[1][1] = value[1][1];
	for (i = 2; i <= N; i++)
		for (j = 1; j <= i; j++)
			dp[i][j] = max(dp[i - 1][j - 1] + value[i][j], dp[i - 1][j] + value[i][j]);

	maxV = 0;
	for (i = 1; i <= N; i++)
		maxV = max(maxV, dp[N][i]);

	printf("%d\n", maxV);

	return 0;
}