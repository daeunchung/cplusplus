#include <stdio.h>
#include <vector>
#include <algorithm> 
using namespace std;
// 소인수분해 
/* 2 3 5 7 .. 소수들로만 이루어진 배열 생성 X, 그냥 n개 칸 배열 만들어서  
	숫자 개수 확인하고 0이 아닌 값만 출력하기 */ 
int main(){
	int i, j, n;	scanf("%d", &n);
	vector<int> a(n+1);	// 편의를 위해 강사님이 n+1개로 
	for(i=2; i<=n; i++){
		int tmp = i;
		j=2; 
		while(1){
			if(tmp%j==0){
				a[j]++;
				tmp/=j;
			}else j++;
			if(tmp==1) break;								
		}
	} 
	printf("%d! = ", n);
	for(i=2; i<=n; i++){
		if(a[i]!=0) printf("%d ", a[i]);
	}
	return 0;
}
