#include <stdio.h>

void fibonacci(int n, int* arr) {
	if (n == 0) {
		arr[0]++;
	}
	else if (n == 1) {
		arr[1]++;
	}
	else {
		fibonacci(n - 1, arr);
		fibonacci(n - 2, arr);
	}
}

int main() { 
	int t, n;
	scanf("%d", &t);
	for (; t--;) {
		scanf("%d", &n);
		int arr[2] = { 0, 0 };
		fibonacci(n, arr);
		printf("%d %d\n", arr[0], arr[1]);

	}
	return 0;
}