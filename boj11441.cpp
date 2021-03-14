//#include <stdio.h>
#include <iostream>
using namespace std;
// 구간합알고리즘(Prefix Sum) 사용 10 20 30 40 50 => {0, 10, 30, 60, 100, 150}
int main(){
	int n, m;
	scanf("%d", &n);
	int sum[n+1] = {0};
	for(int i = 1; i<=n; i++){
		int x;
		scanf("%d", &x);
		sum[i] = sum[i-1] + x;
	}
	scanf("%d", &m);
	int a,b;
	for(int i = 0; i<m; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b] - sum[a-1]);
	}
	return 0;	
}


