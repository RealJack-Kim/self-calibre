#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// น้มุ DP : ล๐ม๗

#include <stdio.h>
#define MAX_N	15

int dp[MAX_N + 1];

int Max_xy(int x, int y)
{
	return (x > y ? x : y);
}

int main(void)
{
	int N;
	int T[MAX_N + 1], P[MAX_N + 1];
	int max;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &T[i], &P[i]);
		dp[i] = P[i];
	}

	for(int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (i - j >= T[j])
			{
				dp[i] = Max_xy(P[i] + dp[j], dp[i]);
			}
		}
	}

	max = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i + T[i] <= N + 1)
		{
			if (dp[i] > max)
				max = dp[i];
		}
	}

	printf("%d\n", max);

	return 0;
}