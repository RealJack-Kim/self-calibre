#include <stdio.h>
#define MAX 100
#define CENTER (MAX/2 - 1)
#define OLD 0
#define NEW 1

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

enum Status {
	EMPTY		= 0,
	NONACTIVE	= 1,
	ACTIVE		= 2,
	KILLED		= 3
};
struct {
	int vital;
	int rest;
	enum Status status;
	int flag;
} cell[MAX][MAX];

void Initialize_cell(void)
{
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
		{
			cell[i][j].status = EMPTY;
			cell[i][j].flag = OLD;
		}
}
void clearflag(void)
{
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			cell[i][j].flag = OLD;
}

int main(void)
{
	int testcase, T;
	int N, M, K;
	int i, j, time, x, y, d;

	if (freopen("sample_input.txt", "r", stdin) == NULL)
		fprintf(stderr, "error redirecting stdin\n");

	scanf("%d", &T);

	for (testcase = 1; testcase <= T; ++testcase)
	{
		Initialize_cell();

		scanf("%d %d %d", &N, &M, &K);
		for (i = CENTER; i < CENTER + N; ++i)
			for (j = CENTER; j < CENTER + M; ++j)
			{
				scanf("%d", &(cell[i][j].vital));
				if (cell[i][j].vital != 0)
				{
					cell[i][j].rest = cell[i][j].vital;
					cell[i][j].status = NONACTIVE;
				}
			}

		for (time = 1; time <= K; ++time)
		{
			for (i = 0; i < MAX; ++i)
				for (j = 0; j < MAX; ++j)
				{
					if (cell[i][j].flag == NEW)
						continue;

					switch (cell[i][j].status)
					{
					case EMPTY:
					case KILLED:
						break;
					case NONACTIVE:
						--(cell[i][j].rest);
						if (cell[i][j].flag != NEW && cell[i][j].rest == 0)
						{
							cell[i][j].status = ACTIVE;
							cell[i][j].rest = cell[i][j].vital;
						}
						break;
					case ACTIVE:
						if (cell[i][j].vital == cell[i][j].rest)
						{
							// 증식
							for (d = 0; d < 4; ++d)
							{
								x = i + dx[d];
								y = j + dy[d];
								if (cell[x][y].status == EMPTY)
								{
									cell[x][y].vital = cell[x][y].rest = cell[i][j].vital;
									cell[x][y].status = NONACTIVE;
									cell[x][y].flag = NEW;
								}
								else if (cell[x][y].flag == NEW)
								{
									if (cell[x][y].vital < cell[i][j].vital)
										cell[x][y].vital = cell[x][y].rest = cell[i][j].vital;
								}
							}
						}
						--(cell[i][j].rest);
						if (cell[i][j].flag != NEW && cell[i][j].rest == 0)
						{
							cell[i][j].status = KILLED;
						}
						break;
					}
				}

			// 동작 확인용
			//printf("\n[K = %d]\n", time);
			//for (i = 0; i < MAX; ++i)
			//{
			//	for (j = 0; j < MAX; ++j)
			//	{
			//		switch (cell[i][j].status)
			//		{
			//		case EMPTY:
			//			printf("0/0/E/%d ", cell[i][j].flag);
			//			break;
			//		case KILLED:
			//			printf("X/X/X/%d ", cell[i][j].flag);
			//			break;
			//		case NONACTIVE:
			//			printf("%d/%d/N/%d ", cell[i][j].vital, cell[i][j].rest, cell[i][j].flag);
			//			break;
			//		case ACTIVE:
			//			printf("%d/%d/A/%d ", cell[i][j].vital, cell[i][j].rest, cell[i][j].flag);
			//			break;
			//		}
			//	}
			//	printf("\n");
			//}

			clearflag();
		}

		int count = 0;
		for (i = 0; i < MAX; ++i)
			for (j = 0; j < MAX; ++j)
			{
				if (cell[i][j].status == NONACTIVE || cell[i][j].status == ACTIVE)
					++count;
			}
		printf("#%d %d\n", testcase, count);
	}
	return 0;
}

