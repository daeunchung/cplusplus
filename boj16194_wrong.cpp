#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
 //O(N제곱)  금액의 최솟값 구하기  // a[] : 카드의 가격 , d[] : 카드 i개 구매하는 최소 비용
//int d[1001] = { MAXX, }; // 배열 초기화 이따구로 안됩니다
int a[1001], d[1001];   
int min(int x, int y)
{
    if (x < y) return x;
    else return y;
}
int main() {
    int n;
    scanf("%d", &n);
    memset(d, 10000000, sizeof(int) * 1001);    // wrong way to use memset
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
             d[i] = min(d[i], d[i - j] + a[j]);
        }
    }
    printf("%d\n", d[n]);
} 
 //C6385 VS error 발생
 //에러의 뜻은 알겠으나, 내 코드(d[i] = min대입부분)에서 왜 발생하는지 모르겠음.
 //배열의 크기를 1001 로 잡아줬고 1<= n <= 1000 인데 
 //읽기 가능한 크기는 '_Old_3'4004'바이트인데 실제로는 '-4'바이트만 읽을 수 있습니다.(?)

