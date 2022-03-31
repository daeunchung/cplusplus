/*
*  Ƚ���� ū�� for�� ��� ���� �ð��ʰ� ������ O(N����)
 ���� �� �˰��� (dp�� ����)
 Prefix sum�� ���صΰ� sum(i)(ó������ i������ ��) - sum(j - 1)(ó������ j - 1������ ��)�� ���ؼ� ��ȯ
 �ð����⵵ : O(n)
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

    // O(N) �Է��� �����鼭 prefix sum�� ä���
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