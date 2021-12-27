/*
화씨를 섭씨온도로 변환하는 ftoc()함수를 사용하여 어셈블리 프로그램을 작성하라.
단 C = 5.0/9.0 * (f – 32)이다.

실행결과
화씨 온도를 입력 하시오 : 32.0
섭씨 온도는 0.000000도 입니다.
*/

#include <stdio.h>
#pragma warning(disable: 4996)

double ftoc(double);
int main(void)
{
	double f, c;
	printf("화씨온도를 입력하시오:");
	scanf("%lf", &f);
	c = ftoc(f);
	printf("섭씨온도는 %f입니다.\n", c);
	return 0;
}

double ftoc(double f) {
	return (5.0 / 9.0) * (f - 32.0);
}