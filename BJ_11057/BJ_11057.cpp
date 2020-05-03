#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 오르막 수

#include <stdio.h>
#define MAX_N	1000
#define divider	10007

long long dp[MAX_N + 1][10];
long long result;

int main(void)
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i][9] = dp[i - 1][9];
		for (int j = 8; j >= 0; j--)
			dp[i][j] = (dp[i - 1][j] + dp[i][j + 1]) % divider;
	}
	for (int i = 0; i <= 9; i++)
		result = (result + dp[N][i]) % divider;

	printf("%lld\n", result);

	return 0;
}