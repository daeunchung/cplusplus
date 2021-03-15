#include <stdio.h>
int main(){
	int a[10], b[10];
	int aa = 0, bb = 0, lw = 0;
	for(int i = 0; i<10; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i<10; i++){
		scanf("%d", &b[i]);
		if(a[i] < b[i]) { bb+=3; lw = 2;}
		else if(a[i] > b[i]) { aa+=3; lw = 1;}
		else { aa++; bb++; }
	}
	printf("%d %d\n", aa, bb);
	if(aa > bb) printf("A");
	else if( aa < bb) printf("B");
	else {
		if(lw == 1) printf("A");
		else if(lw == 2) printf("B");
		else if(lw == 0) printf("D");
	}
	return 0;
}
