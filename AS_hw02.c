#include <stdio.h>
#pragma warning(disable: 4996)

int main() {
	unsigned char str[5], filter = 0xFF;
	unsigned int val;
	printf("4���� ������ �Է� : ");
	scanf("%u", &val);

	val = str[0] << 24 | str[1] << 16 | str[2] << 8 | str[3];

	for (int i = 0; i < 4; i++) {
		printf(" %d th ���� = %u\n", 4-i, val & filter);
		val >>= 8;
	}
}