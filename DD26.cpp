/*
	1. ptr == &ptr[0]
	2. *ptr = ptr[0]
	3. ptr + 1 == ptr에 sizeof(*ptr)을 더한 값
*/
#include <stdio.h>
int main(){
/////////////////////// 배열의 주소 ///////////////////////
	int arr[3] = {1, 2, 3};
	
	printf("arr = %d\n", arr);				// 6553104
	printf("arr + 1 = %d\n", arr + 1);		// 6553108
	printf("%d\n", sizeof(*arr));			// 4
	
	printf("&arr = %d\n", &arr);			// 6553104
	printf("&arr + 1 = %d\n", &arr + 1);	// 6553116 
	printf("%d\n", sizeof(arr));			// 12
	
	// 3.번식에 ptr에 &arr를 대입
	// &arr + 1 == &arr에 sizeof(*(&arr))를 더한 값
	// sizeof(*(&arr)) == sizeof(arr) 
	
	
////////////////////////// 배열 포인터 ////////////////////////
//	int(*포인터이름)[배열의길이];
	int(*ptr_arr)[3];	// 길이 3인 int형배열을 가리키는 포인터를 선언
	ptr_arr = &arr;		// 초기화 
	for(int i = 0; i<3; i++)
		printf("%d ", (*ptr_arr)[i]);
	
} 
