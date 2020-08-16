#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 2xn 타일링

#include <stdio.h>
#define MAX_n	1000
#define Divisor	10007

int dp[MAX_n];

int main(void)
{
	int n;

	scanf("%d", &n);

	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= Divisor;
	}
	
	printf("%d\n", dp[n]);

	return 0;
}