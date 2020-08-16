#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 가장 긴 증가하는 부분 수열

#include <stdio.h>
#define MAX_LEN_N	1000

int dp[MAX_LEN_N + 1];
int A[MAX_LEN_N + 1];

int Max(int x, int y)
{
	return (x >= y ? x : y);
}

int main(void)
{
	int N, max;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);

	dp[1] = 1;
	max = 1;
	for (int i = 2; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i - 1; j++)
		{
			if (A[i] > A[j])
			{
				dp[i] = Max(dp[i], dp[j] + 1);
			}
		}
		max = Max(max, dp[i]);
	}

	printf("%d\n", max);

	return 0;
}