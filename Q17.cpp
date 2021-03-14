#include <stdio.h>
int n, a, b;
int main(){
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		scanf("%d %d", &a, &b);
		if(b == a*(a+1)/2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
