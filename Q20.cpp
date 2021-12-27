#include <stdio.h>
int main(){
	int n;	scanf("%d", &n);
	int *a = new int[n];
	int *b = new int[n];
	for(int i = 0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i<n; i++){
		scanf("%d", &b[i]);
	}
	for(int i = 0; i<n; i++){
		if(a[i]==1 && b[i]==2 || a[i]==2 && b[i]==3 || a[i]==3 && b[i]==1) printf("B\n");
		else if(a[i]==2 && b[i]==1 || a[i]==3 && b[i]==2 || a[i]==1 && b[i]==3) printf("A\n");
		else printf("D\n");
	}
	return 0;
}
