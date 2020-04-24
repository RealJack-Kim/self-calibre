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

	// 1st Solution
	/*
		if (N * 2 > M)
			N = M - N;
		
		for (int i = M; i >= M - (N - 1); i--)	// mPn = m * (m-1) * (m-2) * ... * (m-(n-1))
			result *= i;

		for (int i = N; i >= 1; i--)	// mPn / n!
			result /= i;
	*/
	
	// 2nd Solution
		dp[N][N] = 1;
		dp[N][N - 1] = N;
		for (int i = N + 1; i <= M; i++)
			dp[i][N] = dp[i - 1][N - 1] + dp[i - 1][N];
		result = dp[M][N];

		printf("%lld\n", result);
	}
	return 0;
}