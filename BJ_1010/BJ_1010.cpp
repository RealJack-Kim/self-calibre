#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 다리 놓기 (nCr = n-1Cr + n-1Cr-1)

#include <stdio.h>
#define MAX_NM	30

long long dp[MAX_NM][MAX_NM];
long long result = 1;

int main(void)
{
	int T, N, M;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &N, &M);
		if (N * 2 > M)
		{
			N = M - N;
		}
		
		for (int i = M; i >= M - (N - 1); i--)
		{
			result *= i;
		}
		for (int i = N; i >= 1; i--)
		{
			result /= i;
		}

		printf("%lld\n", result);
	}
	return 0;
}