// �迭 ������ : �ϳ��� �迭�� ����Ű�� �ϳ��� ������
// ������ �迭 : �������� �����͵��� �迭�� ���ִ� ��  
#include <stdio.h>
int main(){
	int *ptr[4];	// �����͹迭
	
	int a=10, b=20, c=30, d=40;
	ptr[0]=&a;
	ptr[1]=&c;
	ptr[2]=&d;
	ptr[3]=&b;
	for(int i=0; i<4; i++)
		printf("%d ", ptr[i]);
	printf("\n");
	for(int i=0; i<4; i++)
		printf("%d ", *ptr[i]);
	printf("\n");
	
	int arr[4] = {1, 2, 3, 4};
	for(int i = 0; i<4; i++)
		ptr[i] = &arr[i];
	for(int i = 0; i<4; i++)
		printf("%d ", *ptr[i]);
} 
