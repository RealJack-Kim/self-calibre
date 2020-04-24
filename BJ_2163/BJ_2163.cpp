#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 초콜릿 자르기

// Simple solution
/*
#include <stdio.h>

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);
	printf("%d\n", N * M - 1);

	return 0;
}
*/

// DP Solution
#include <stdio.h>

#define MAX_N	300
int dp[MAX_N + 1][MAX_N + 1];

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	dp[1][M] = M - 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i][M] = dp[i - 1][M] + dp[1][M] + 1;
	}

	printf("%d\n", dp[N][M]);

	return 0;
}
