// 이분탐색 + parametric search
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 2000000000
#define MAXN 1000000

int N, M;
int Wood[MAXN];

//  결정함수 parametric search
bool fmax(int size)
{
	long long h = 0;
	for (int i = 0; i < N; i++) {
		if (Wood[i] - size > 0) h += (Wood[i] - size);
	}
	if (h >= M) return true;
	else return false;
}

int main()
{
	int lb = 0, ub = 0, m;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &Wood[i]);;
		ub = max(ub, Wood[i]);	// 가장 긴 나무의 길이 찾기
	}

	// 이분탐색
	while (lb+1 < ub)
	{
		m = lb + (ub - lb) / 2;
		if (fmax(m)) lb = m;
		else ub = m;
	}
	printf("%d", lb);
	return 0;
}
