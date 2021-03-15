#include <stdio.h>
int DFS(int n){
	if(n==1) return 1;
	else return n*DFS(n-1);
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", DFS(n));
	return 0;
}
