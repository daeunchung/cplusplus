#include <stdio.h>
int n, m, a, max = -1, cnt, trigger;
int main(){
	scanf("%d %d", &n, &trigger);
	for(int i = 0; i<n; i++){
		scanf("%d", &a);
		if(a > trigger)
			cnt++;
		else
			cnt = 0;
		if(max < cnt)
			max = cnt;
	}
	if(max == 0) printf("-1\n");
	else printf("%d", max);
	return 0;
}
