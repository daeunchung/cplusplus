#include <stdio.h>

void main() {
	int i, j;
	int arr[] = { 3, 6, 7,1,5,4 };
	int n = sizeof(arr) / sizeof(int);

	// i<<n : 부분집합의 수 , n : 원소의 수 , 1<<j : i의 j번째 bit
	for (int i = 0; i < (1<<(n)); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				printf("%d ", arr[j]);
			}
		}
		printf("\n");
	}
}