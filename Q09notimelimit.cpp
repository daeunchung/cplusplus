#include <stdio.h>
using namespace std;
int main(){
//	freopen("input.txt", "rt", stdin);
	int num, i, d, cnt = 0;
	scanf("%d", &num);
	for(i = 1; i <= num; i++){
		for(d = 1; d <= i; d++){
			if(i % d == 0) cnt++;
		}
		printf("%d ", cnt);
		cnt = 0;
	}
	return 0;
}
