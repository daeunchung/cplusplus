#include <stdio.h>
#define SIZE 7
int main(void) {
	int list[SIZE]; int i = 0;
	printf("���� 7���� �Է��Ͻÿ� ");
	for (int i = 0; i < SIZE; i++)
		scanf("%d", &list[i]);
	for (i = 0; i < SIZE; i++)
		list[i] = list[i] * list[i];
	printf("���� 7���� ���\n");
	for (i = 0; i < SIZE; i++)
		printf("%3d ", list[i]);
	printf("\n");
	return 0;
}
