/*
*  횟수가 큰데 for문 계속 돌면 시간초과 나겠지 O(N제곱)
 누적 합 알고리즘 (dp의 일종)
 Prefix sum을 구해두고 sum(i)(처음부터 i까지의 합) - sum(j - 1)(처음부터 j - 1까지의 합)을 통해서 반환
 시간복잡도 : O(n)
y0 = x0
y1 = x0 + x1
y2 = x0 + x1 + x2
...
yN = x0 + x1 + ... + xN

S[j] - S[i-1] = a[i] + a[i+1] + ... + a[j-1] + a[j]
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_N 100001
#define MAX_M 100001
using namespace std;
int v[MAX_N];
int sum[MAX_N];

int main()
{
    int N, M;

    scanf("%d %d", &N, &M);

    // O(N) 입력을 받으면서 prefix sum을 채운다
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &v[i]);
        sum[i] = sum[i - 1] + v[i];
    }
    while (M--) {
        int from, to;
        scanf("%d %d", &from, &to);
        printf("%d\n", sum[to] - sum[from - 1]);
    }
    return 0;
}