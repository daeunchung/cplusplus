#include <stdio.h>
int digit_sum(int x){
	int ans = 0;
	while(x != 0){
		ans += x%10;
		x /= 10;
	}
	return ans;
}
int n, a, ans;
int main(){
//	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		scanf("%d", &a);
		if(digit_sum(a) > digit_sum(ans))
			ans = a;
		else if (digit_sum(a) == digit_sum(ans))
			(a>ans) ? ans = a : ans;
	}
	printf("%d", ans);
	return 0;
}

