#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// O(NÁ¦°ö)
int a[1001];
int d[1001];
int max(int x, int y)
{
    if (x > y) return x;
    else return y;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int p;     scanf("%d", &p);
        a[i] = p;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            d[i] = max(d[i], d[i - j] + a[j]);
        }
    }
    printf("%d\n", d[n]);
}