#include <stdio.h>
int i;
int main(){
	int num;	scanf("%d", &num);
	int *n = new int[num];
	for(i = 0; i<num; i++){
		scanf("%d", &n[i]);
	}
	int cnt = 0;
	int max = n[num-1];
	for(i = num-2; i>=1; i--){
		if(n[i] > max){
			max = n[i];
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}

