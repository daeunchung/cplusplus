#include <stdio.h>
int main(){
//	freopen("input.txt", "rt", stdin);
	int a[101], n, tmp, idx, i, j, cnt=1;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	////////////////////////////// SelectionSort//
	for(i=0; i<n-1; i++){
		idx=i;
		for(j=i+1; j<n; j++){
			if(a[j]>a[idx]) idx=j;
		}
		tmp=a[i];
		a[i]=a[idx];
		a[idx]=tmp;
	}
	///////////////////////////////////////////////
	tmp=a[0]; 
	for(i=1; i<n; i++){
		if(tmp>a[i]) {
			cnt++;
			tmp=a[i];	
		}
		if(cnt==3) break;
	}
	printf("%d\n", tmp);
	return 0;
}
