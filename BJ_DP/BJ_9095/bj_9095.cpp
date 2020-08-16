#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 1,2,3 더하기

#include <stdio.h>
#define MAX_N	11

int dp[MAX_N + 1];

int main(void)
{
	int T;
	int n[MAX_N + 1];

	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
		scanf("%d", &n[tc]);

	dp[1] = 1;
	dp[2] = dp[1] + 1;
	dp[3] = dp[2] + dp[1] + 1;
	for (int tc = 1; tc <= T; tc++)
	{
		for (int i = 4; i <= n[tc]; i++)
		{
			if(dp[i] == 0)
				dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		printf("%d\n", dp[n[tc]]);
	}

	return 0;
}