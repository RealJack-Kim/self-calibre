#ifdef _MSC_VER
#define  _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	FILE* fp = freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	return 0;
}