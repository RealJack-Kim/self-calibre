#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 가장 큰 증가 부분 수열

#include <stdio.h>
#define MAX_N	1000

int dp[MAX_N + 1], A[MAX_N + 1];

int max_xy(int x, int y)
{
	return (x > y ? x : y);
}

int main(void)
{
	int N, result;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);

	for (int i = 1; i <= N; i++)
	{
		dp[i] = A[i];
		for (int j = 1; j < i; j++)
		{
			if (A[i] > A[j])
			{
				dp[i] = max_xy(dp[i], dp[j] + A[i]);
			}
		}
	}

	result = 0;
	for (int i = 1; i <= N; i++)
		result = max_xy(result, dp[i]);

	printf("%d\n", result);

	return 0;
}