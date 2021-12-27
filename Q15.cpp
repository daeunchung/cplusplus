#include <stdio.h>
// 제한시간 1초  2<=N<=200,000 
int main(){
	int i, j, n, cnt=0, flag;
	scanf("%d", &n);
	for(i = 2; i<= n; i++){
		flag = 1;
		for(j = 2; j*j<= i; j++){
			if(i % j == 0){
				flag = 0;
				break;
			}
		}
		if(flag == 1)cnt++;
	}
	printf("%d", cnt);
	return 0;
} 
