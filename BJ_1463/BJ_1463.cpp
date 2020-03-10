#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 1로 만들기

#include <stdio.h>
#define MAX_N	1000001

int dp[MAX_N];

int min(int x, int y)
{
	return (x < y ? x : y);
}

int main(void)
{
	int N;
	int tmp;

	scanf("%d", &N);

	dp[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		tmp = dp[i - 1] + 1;
		if (i % 3 == 0)
			tmp = min(tmp, dp[i / 3] + 1);
		if (i % 2 == 0)
			tmp = min(tmp, dp[i / 2] + 1);

		dp[i] = tmp;
	}
	printf("%d\n", dp[N]);

	return 0;
}

/*
int solve(int n)
{
	int tmp;

	if (n == 1)
		return 0;

	if (dp[n] != -1)
		return dp[n];

	if (n % 3 == 0 && n % 2 == 0)
	{
		tmp = min(solve(n / 3) + 1, solve(n / 2) + 1);
		dp[n] = min(tmp, solve(n - 1) + 1);
	}
	else if (n % 3 == 0)
		dp[n] = min(solve(n - 1) + 1, solve(n / 3) + 1);
	else if (n % 2 == 0)
		dp[n] = min(solve(n - 1) + 1, solve(n / 2) + 1);
	else
		dp[n] = solve(n - 1) + 1;

	return dp[n];
}
*/