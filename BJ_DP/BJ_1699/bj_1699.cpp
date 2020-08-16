#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 제곱수의 합

#include <stdio.h>
#define MAX_N	100000

int dp[MAX_N + 1];

int min_xy(int x, int y)
{
	return (x < y ? x : y);
}

int main(void)
{
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		dp[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = min_xy(dp[i], dp[i - j * j] + 1);
		}
	}

	printf("%d\n", dp[N]);

	return 0;
}