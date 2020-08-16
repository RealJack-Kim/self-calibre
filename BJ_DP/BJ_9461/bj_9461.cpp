#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

// 백준 DP : 파도반 수열

#include <stdio.h>
#define MAX_N	100
long long int P[MAX_N + 1];

int main(void)
{
	int T, N, max_N;

	scanf("%d", &T);

	P[1] = P[2] = P[3] = 1L;
	P[4] = P[5] = 2L;
	max_N = 5;
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);

		if (N > max_N)
		{
			for (int j = max_N + 1; j <= N; j++)
			{
				P[j] = P[j - 1] + P[j - 5];
			}
			max_N = N;
		}

		printf("%lld\n", P[N]);
	}

	return 0;
}