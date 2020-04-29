#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 다리 놓기 (nCr = n-1Cr + n-1Cr-1)

#include <stdio.h>
#include <memory.h>
#define MAX_NM	30

long long dp[MAX_NM][MAX_NM];
long long result = 1;

long long combi(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	if (dp[n][r])
		return dp[n][r];
	return dp[n][r] = combi(n - 1, r - 1) + combi(n - 1, r);
}

int main(void)
{
	int T, N, M;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		memset(dp, 0, sizeof(dp));
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
	/*
		result = combi(M, N);
	*/

	// 3rd Solution
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (j == 1)
					dp[i][j] = i;
				else if (j == i)
					dp[i][j] = 1;
				else
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
		result = dp[M][N];

		printf("%lld\n", result);
	}
	return 0;
}