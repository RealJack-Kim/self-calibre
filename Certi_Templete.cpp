#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif
/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// scanf("%d", &a);                      // int ���� 1�� �Է¹޴� ����
// scanf("%f %f", &b, &c);               // float ���� 2�� �Է¹޴� ���� 
// scanf("%lf %lf %lf", &d, &e, &f);     // double ���� 3�� �Է¹޴� ����
// scanf("%c", &g);                      // char ���� 1�� �Է¹޴� ����
// scanf("%s", &var);                    // ���ڿ� 1�� �Է¹޴� ����
// scanf("%lld", &AB);                   // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// printf("%d", a);                      // int ���� 1�� ����ϴ� ����
// printf("%f %f", b, c);                // float ���� 2�� ����ϴ� ����
// printf("%lf %lf %lf", d, e, f);       // double ���� 3�� ����ϴ� ����
// printf("%c", g);                      // char ���� 1�� ����ϴ� ����
// printf("%s", var);                    // ���ڿ� 1�� ����ϴ� ����
// printf("%lld", AB);                   // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

int main(void)
{
	int test_case, T;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		printf("#%d\n", test_case);
	}

	return 0;
}