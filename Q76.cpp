/* �޸������̼�(memoization)�� ��ǻ�� ���α׷��� ������ ����� �ݺ��ؾ� �� ��, 
������ ����� ���� �޸𸮿� ���������ν� ������ ����� �ݺ� ������ �����Ͽ� 
���α׷� ���� �ӵ��� ������ �ϴ� ����̴�. ���� ��ȹ���� �ٽ��� �Ǵ� ����̴� */

// ���װ�� nCr = n-1Cr-1 + n-1Cr (������ + ������) 
// �ݺ��ؼ� ������ ����� ���ϱ� ���� Ʈ���� ��� ���ƾ��Ѵ�. ���� �迭�� Memoization
#include <stdio.h>
using namespace std;
int dy[21][21];	// �޸������̼��� ���� 0���� �ʱ�ȭ�� �迭 
int C(int n, int r){
	if(dy[n][r]>0) return dy[n][r];
	if(n==r || r==0) return 1;
	else return dy[n][r] = C(n-1, r-1)+C(n-1, r);
} 
int main(){
//	freopen("input.txt", "rt", stdin);
	int n, r;
	scanf("%d %d", &n, &r);
	printf("%d\n", C(n, r));
	return 0;
}




