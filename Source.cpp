// Debug��忡�� F5(�����) Alt+6 (�޸�â) F9(Breakpoint)
#include <stdio.h>
int main() {
	int cnt = 10;
	
	int cnt1 = 1;
	int arr1[5] = { 5,5,5,5,5 };
	int cnt2 = 2;
	int arr2[5] = { 6,6,6,6,6 };
	int cnt3 = 3;
	// �����ϱ⿡�� cnt1 arr1 cnt2 arr2 cnt3 ������ �޸𸮿� ����Ǿ�� ������
	// ���� �޸� ������ ��ġ�� (�����ּ�) cnt3 - cnt2 - cnt1 - arr2 - arr1 (�����ּ�) 
	// ���� �ڷᱸ�� �˰������� ���� ���� ���� ����.
	// ���� �߰��߰� ���ʿ��غ��̴� �޸� ������ ���δ�.
	// �޸𸮰����� OS����, IDE ���� �ٸ� �������� ����.

	long *heap_data = malloc(8);
	// 64bit ��ǻ�Ϳ��� �޸� ������ �������ϱ� ���ؼ��� ������ 64bit �ʿ� => 8byte �����Ҵ�
	*heap_data = 0XAABBCCDDEEFF0000;
	// ���������� STACK��,
	// �����ͺ����� heap_data�� STACK��, 
	// �����Ͱ� ����Ű�� ������ *heap_data�� �����Ҵ���� HEAP��

	printf("%p\n", &cnt);
	printf("%d\n", cnt);
	
	printf("%X\n", *(&cnt + 128));
	return 0;

}
/*
 1byte = 8bit
 C(16) = 16(10) = 1111(2)
 CC(16) = 11111111(2) = 8bit = 1byte 
 x86(x86-64)�迭 CPU�� ��Ʋ����� ����� ���� �ڿ������� �ΰ��� �о���Ѵ�.
 
 ex) E0 1A 64 00 01 00 00 00 => 00 00 00 01 00 64 1A E0
 */