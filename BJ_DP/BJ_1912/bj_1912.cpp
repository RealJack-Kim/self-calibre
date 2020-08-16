#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#define MAX_n	100000

int dp[MAX_n + 1];
int num[MAX_n + 1];

int max(int x, int y)
{
	return (x > y ? x : y);
}

int main(void)
{
	int n;
	int maxS;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);

	dp[1] = num[1];
	maxS = dp[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(num[i], dp[i - 1] + num[i]);
		maxS = max(maxS, dp[i]);
	}

	printf("%d\n", maxS);

	return 0;
}