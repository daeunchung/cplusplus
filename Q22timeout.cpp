#include <stdio.h>
int main(){
	int i, n, m, sum = 0, max = -200;
	scanf("%d %d", &n, &m);
//	int *t = new int[n];
	vector<int> t(n);
//	int *sum = new int[n-m+1];
	for(i = 0; i<n; i++){
		scanf("%d", &t[i]);
	} 
	for(i = 0; i<=n-m; i++){
		sum = 0;
		for(int k = i; k<i+m; k++){
			sum[i] += t[k];
		}
		if(sum[i] > max)
			max = sum[i];
	}
	printf("%d\n", max);
	return 0;
}
