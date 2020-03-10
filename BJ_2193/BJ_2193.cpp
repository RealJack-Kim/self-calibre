#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 이친수

#include <stdio.h>
#define MAX_N	90

long long dp[MAX_N + 1][2];

int main(void)
{
	int N;

	scanf("%d", &N);

	dp[1][0] = 0L;
	dp[1][1] = 1L;
	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	printf("%lld\n", dp[N][0] + dp[N][1]);

	return 0;
}