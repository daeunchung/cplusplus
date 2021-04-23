#include <iostream>
using namespace std;

static void func1()	// 정적 선언 함수
{
	static char arr1[10000000];
}

void func2()		// 스택에 선언 함수
{
	char arr2[10000000];
}

void func3()		// 힙에 선언 함수
{
	char* arr3 = new char[10000000];
	delete arr3;
}

int main() {
	for (int i = 0; i < 200000; i++)
	{
		func1();
		func2();
		func3();
	}
}