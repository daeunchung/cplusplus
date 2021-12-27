#include <stdio.h>
#pragma warning(disable: 4996)

int sum(int, int[]);
int main() {
	int n = 5; // n :the number of array element
	int a[n];
	int total, i;
	printf("Enter integer 5 number : \n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	total = sum(n, a);
	printf("Total = % d\n", total);
		return 0;
}
int sum(int n, int a[]) {
	int total = 0;
	while (n-- > 0)
		total += a[n];
	return total;
}