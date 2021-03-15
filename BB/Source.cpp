// Debug모드에서 F5(디버그) Alt+6 (메모리창) F9(Breakpoint)
#include <stdio.h>
int main() {
	int cnt = 10;
	
	int cnt1 = 1;
	int arr1[5] = { 5,5,5,5,5 };
	int cnt2 = 2;
	int arr2[5] = { 6,6,6,6,6 };
	int cnt3 = 3;
	// 생각하기에는 cnt1 arr1 cnt2 arr2 cnt3 순으로 메모리에 저장되어야 하지만
	// 실제 메모리 공간상 위치는 (낮은주소) cnt3 - cnt2 - cnt1 - arr2 - arr1 (높은주소) 
	// 스택 자료구조 알고있으면 원리 쉽게 이해 가능.
	// 또한 중간중간 불필요해보이는 메모리 공간도 보인다.
	// 메모리관리는 OS마다, IDE 마다 다른 패턴으로 동작.

	long *heap_data = malloc(8);
	// 64bit 컴퓨터에서 메모리 공간을 포인팅하기 위해서는 동일한 64bit 필요 => 8byte 공간할당
	*heap_data = 0XAABBCCDDEEFF0000;
	// 지역변수는 STACK에,
	// 포인터변수는 heap_data는 STACK에, 
	// 포인터가 가리키는 데이터 *heap_data는 동적할당받은 HEAP에

	printf("%p\n", &cnt);
	printf("%d\n", cnt);
	
	printf("%X\n", *(&cnt + 128));
	return 0;

}
/*
 1byte = 8bit
 C(16) = 16(10) = 1111(2)
 CC(16) = 11111111(2) = 8bit = 1byte 
 x86(x86-64)계열 CPU는 리틀엔디언 방식을 따라서 뒤에서부터 두개씩 읽어야한다.
 
 ex) E0 1A 64 00 01 00 00 00 => 00 00 00 01 00 64 1A E0
 */