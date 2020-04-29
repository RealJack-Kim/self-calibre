#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 동전1

#include <stdio.h>
#define MAX_N	100
#define MAX_K	10000

int dp[MAX_K + 1], coin[MAX_N + 1];

int main(void)
{
	int n, k;

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &coin[i]);

	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			dp[j] += dp[j - coin[i]];
		}
	}

	printf("%d\n", dp[k]);

	return 0;
}