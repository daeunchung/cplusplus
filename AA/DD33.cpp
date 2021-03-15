#include <stdio.h>
 //call-by-value
void swap(int x, int y){
	int tmp = x;
	x=y;
	y=tmp;
}
int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	swap(a, b);
	printf("a = %d, b = %d\n", a, b);
}


 //call-by-reference (실존정의X, 임의로 C에서 포인터를받아와서 swap) 
void swap(int *x, int *y){
	int tmp = *x;
	*x=*y;
	*y=tmp;
}
int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
}


 //call-by-reference in C++
void swap(int &x, int &y){
	int tmp = x;
	x=y;
	y=tmp;
}
int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	swap(a, b);
	printf("a = %d, b = %d\n", a, b);
}
