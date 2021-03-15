#include <stdio.h>
#include <vector>
#include <algorithm> 
#include <cmath>
using namespace std;

// 내 방법 // 정답코드는 다름 확인해야함 
int main(){
	int i, n, cnt=0, a=0;
	scanf("%d", &n);
	int tmp = n;
	while(tmp != 0){
		cnt++;
		tmp/=10;
	}
	for(i=1; i<=cnt-1; i++)
		a += pow(10, i);
	printf("%d", cnt*n + - a + (cnt-1));
	return 0;
}


