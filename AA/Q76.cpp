/* 메모이제이션(memoization)은 컴퓨터 프로그램이 동일한 계산을 반복해야 할 때, 
이전에 계산한 값을 메모리에 저장함으로써 동일한 계산의 반복 수행을 제거하여 
프로그램 실행 속도를 빠르게 하는 기술이다. 동적 계획법의 핵심이 되는 기술이다 */

// 이항계수 nCr = n-1Cr-1 + n-1Cr (나포함 + 나제외) 
// 반복해서 동일한 결과를 구하기 위해 트리가 계속 돌아야한다. 따라서 배열로 Memoization
#include <stdio.h>
using namespace std;
int dy[21][21];	// 메모이제이션을 위한 0으로 초기화된 배열 
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




