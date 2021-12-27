//#include <stdio.h>
//#include <string.h>
//int fun(int* k) {
//	*k += 4;
//	return 3 * (*k) - 1;
//}
//int main() {
//	int i = 10, j = 10, sum1, sum2;
//	sum1 = (i / 2) + fun(&i);
//	//sum1 = i + fun(&i);
//	printf(" sum1 = %d \n", sum1);
//
//	sum2 = fun(&j) + (j / 2);
//	//sum2 = fun(&j) + j;
//	printf(" sum2 = %d \n", sum2);
//	return 0;
//}
// 
// 
//int constAdd(int* pa) {
//	*pa += 20;
//	return *pa;
//}
//int main() {
//	int a = 10;
//	int b = a + constAdd(&a);
//	printf(" b = %d\n", b);
//
//	a = 10;
//	b = constAdd(&a) + a;
//	printf(" b = %d\n", b);
//}

#include <stdio.h>
//int main() {
//	float fNum = 23.2323;
//	char cNum = (char)fNum;
//
//	printf("intNum = %c", cNum);
//}
int a = 5;
int fun1() { a = 17;	return 3; }
void main() {
	a = a + fun1();
	printf("%d", a);
}