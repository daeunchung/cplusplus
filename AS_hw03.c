#include <stdio.h>
#pragma warning(disable: 4996)
int main(){
	int year = 0;
	while (1) {
		printf("input year : ");
		scanf("%d", &year);
		if (year < 0)
		{
			printf("����.\n");
			break;
		}
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			printf("%d �����Դϴ�.\n", year);
		else
			printf("%d ����Դϴ�.\n", year);
	}
}