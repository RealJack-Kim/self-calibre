#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 포도주 시식 (계단 문제와 유사. 단, i-th 잔은 마시지 않아도 되는 것이 다름.)

#include <stdio.h>
#define MAX_n	10000

int dp[MAX_n + 1];
int wine[MAX_n + 1];

int max(int x, int y)
{
	return (x > y ? x : y);
}

int main(void)
{
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &wine[i]);

	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		dp[i] = max(dp[i], dp[i - 3] + wine[i - 1] + wine[i]);
		dp[i] = max(dp[i], dp[i - 2] + wine[i]);
	}

	printf("%d\n", dp[n]);

	return 0;
}