#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : RGB 거리

#include <stdio.h>
#define MAX_N	1000

int dp[MAX_N + 1][3];
int R[MAX_N + 1], G[MAX_N + 1], B[MAX_N + 1];

int min(int x, int y)
{
	return (x < y ? x : y);
}

int main(void)
{
	int N;
	int minV;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d %d", &R[i], &G[i], &B[i]);

	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = min(dp[i - 1][1] + R[i], dp[i - 1][2] + R[i]);
		dp[i][1] = min(dp[i - 1][0] + G[i], dp[i - 1][2] + G[i]);
		dp[i][2] = min(dp[i - 1][0] + B[i], dp[i - 1][1] + B[i]);
	}
	minV = min(dp[N][0], dp[N][1]);
	minV = min(minV, dp[N][2]);

	printf("%d\n", minV);

	return 0;
}