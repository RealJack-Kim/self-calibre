#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 쉬운 계단수

#include <stdio.h>

#define	Mod	1000000000
#define	MAX_N	100

int dp[MAX_N+1][10];

int main(void)
{
	int N;
	int num;

	scanf("%d", &N);
	for (int j = 1; j < 10; j++)
		dp[1][j] = 1;

	for (int i = 2; i <= N; i++)
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

			dp[i][j] %= Mod;
		}

	num = 0;
	for (int j = 0; j < 10; j++)
	{
		num += dp[N][j];
		num %= Mod;
	}

	printf("%d\n", num);

	return 0;
}