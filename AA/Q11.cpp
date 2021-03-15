#include <stdio.h>
int main(){
//	freopen("input.txt", "rt", stdin);
	int n, cnt = 0, tmp;
	scanf("%d", &n);
	for(int i = 1; i<n; i++){
		tmp = i;
		if(tmp > 0){
			tmp /= 10;
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}
