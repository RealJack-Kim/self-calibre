#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 계단 오르기

#include <stdio.h>
#define MAX_N	300

int dp[MAX_N + 1];

int max(int x, int y)
{
	return (x > y ? x : y);
}

int main(void)
{
	int N;
	int V[MAX_N + 1];

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &V[i]);

	dp[0] = 0;
	dp[1] = V[1];
	dp[2] = V[1] + V[2];
	for (int i = 3; i <= N; i++)
		dp[i] = max(dp[i - 3] + V[i - 1] + V[i], dp[i - 2] + V[i]);

	printf("%d\n", dp[N]);

	return 0;
}