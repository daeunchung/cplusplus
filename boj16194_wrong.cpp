#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
 //O(N����)  �ݾ��� �ּڰ� ���ϱ�  // a[] : ī���� ���� , d[] : ī�� i�� �����ϴ� �ּ� ���
//int d[1001] = { MAXX, }; // �迭 �ʱ�ȭ �̵����� �ȵ˴ϴ�
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
 //C6385 VS error �߻�
 //������ ���� �˰�����, �� �ڵ�(d[i] = min���Ժκ�)���� �� �߻��ϴ��� �𸣰���.
 //�迭�� ũ�⸦ 1001 �� ������ 1<= n <= 1000 �ε� 
 //�б� ������ ũ��� '_Old_3'4004'����Ʈ�ε� �����δ� '-4'����Ʈ�� ���� �� �ֽ��ϴ�.(?)

