#include <iostream>
using namespace std;

static void func1()	// ���� ���� �Լ�
{
	static char arr1[10000000];
}

void func2()		// ���ÿ� ���� �Լ�
{
	char arr2[10000000];
}

void func3()		// ���� ���� �Լ�
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