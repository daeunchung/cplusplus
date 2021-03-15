#include <stdio.h>
int n[10];
int main(){
//	freopen("input.txt", "rt", stdin);
	int max = -1, digit, ans;
	char a[101];
	scanf("%s", &a);
	for(int i = 0; a[i] != '\0'; i++){
		digit = a[i] - 48;
		n[digit]++;
	}
	for(int i = 0; i < 10; i++){	// 작은수 ~ 큰수 순서로 조회하니 >= 넣어주면 자동 큰수로 change 
		if(n[i] >= max){
			max = n[i];
			ans = i;	
		}
	}
	printf("%d\n", ans);
	return 0;
}
