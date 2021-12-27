#include <stdio.h>

void main() {
	int i, j;
	int arr[] = { 3, 6, 7,1,5,4 };
	int n = sizeof(arr) / sizeof(int);

	// i<<n : �κ������� �� , n : ������ �� , 1<<j : i�� j��° bit
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