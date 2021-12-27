/*
	1. ptr == &ptr[0]
	2. *ptr = ptr[0]
	3. ptr + 1 == ptr�� sizeof(*ptr)�� ���� ��
*/
#include <stdio.h>
int main(){
/////////////////////// �迭�� �ּ� ///////////////////////
	int arr[3] = {1, 2, 3};
	
	printf("arr = %d\n", arr);				// 6553104
	printf("arr + 1 = %d\n", arr + 1);		// 6553108
	printf("%d\n", sizeof(*arr));			// 4
	
	printf("&arr = %d\n", &arr);			// 6553104
	printf("&arr + 1 = %d\n", &arr + 1);	// 6553116 
	printf("%d\n", sizeof(arr));			// 12
	
	// 3.���Ŀ� ptr�� &arr�� ����
	// &arr + 1 == &arr�� sizeof(*(&arr))�� ���� ��
	// sizeof(*(&arr)) == sizeof(arr) 
	
	
////////////////////////// �迭 ������ ////////////////////////
//	int(*�������̸�)[�迭�Ǳ���];
	int(*ptr_arr)[3];	// ���� 3�� int���迭�� ����Ű�� �����͸� ����
	ptr_arr = &arr;		// �ʱ�ȭ 
	for(int i = 0; i<3; i++)
		printf("%d ", (*ptr_arr)[i]);
	
} 
