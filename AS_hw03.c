#include <stdio.h>
#pragma warning(disable: 4996)
int main(){
	int year = 0;
	while (1) {
		printf("input year : ");
		scanf("%d", &year);
		if (year < 0)
		{
			printf("종료.\n");
			break;
		}
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			printf("%d 윤년입니다.\n", year);
		else
			printf("%d 평년입니다.\n", year);
	}
}