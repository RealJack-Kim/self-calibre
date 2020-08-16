#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 카드 구매하기 (1 <= N <= 1000, 1<= Pi <= 10000)

#include <stdio.h>
#define MAX_N	1000

int dp[MAX_N + 1], P[MAX_N + 1];

int Max_xy(int x, int y)
{
	return (x > y ? x : y);
}

int main(void)
{
	int N, max_i;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &P[i]);

	dp[1] = P[1];
	for (int i = 2; i <= N; i++)
	{
		max_i = 1;
		for (int j = 1; j <= i; j++)
		{
			max_i = Max_xy(max_i, dp[i - j] + P[j]);
		}
		dp[i] = max_i;
	}

	printf("%d\n", dp[N]);

	return 0;
}