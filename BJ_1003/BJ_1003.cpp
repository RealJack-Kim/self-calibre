#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 피보나치 함수

#include <stdio.h>
#define MAX_N   40

int dp[MAX_N + 1][2];

int main(void)
{
    int T, n;

    dp[0][0] = dp[1][1] = 1;
    dp[0][1] = dp[1][0] = 0;
    for (int i = 2; i <= MAX_N; i++)
    {
        dp[i][0] = dp[i - 2][0] + dp[i - 1][0];
        dp[i][1] = dp[i - 2][1] + dp[i - 1][1];
    }

    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d", &n);
        printf("%d %d\n", dp[n][0], dp[n][1]);
    }

	return 0;
}