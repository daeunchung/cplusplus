/*
static_cast : 정적(컴파일타임)
dynamic_cast : 동적(런타임)

C++ 에서 virtual로 동적 바인딩을 활용하기 위해서는 RTTI가 필요하다. 즉 RTTI를 사용해서 dynamic_cast를 하는 것
RTTI (Run Time Type Information/Identification)

C++에는 두가지 클래스 1)가상함수가 없는클래스		2)가상함수가 하나라도 있는클래스 (다형 클래스)

Base클래스로부터 Derived클래스로 dynamic_cast를 해주고 싶으면 Base클래스는 반드시 virtual가상함수가 한개이상 포함된 다형 클래스여야 한다
다형클래스여야만 RTTI를 지원해서 dynamic_cast를 가능하게 해주기 때문
*/
#include <iostream>
using namespace std;

class Base {
public:
	virtual void f(){}
	int x = 10;
};

class Derived : public Base {
public:
	void f(){}
	int y = 20;
};
 
int main() {
	cout << sizeof(Base) << endl;		// Base클래스 virtual함수 f()때문에 구조가 4byte(포인터) + 4byte(int x) // 8
	cout << sizeof(Derived) << endl;	// 4byte(포인터) + 4byte(int x) + 4byte(int y)						  // 12

	int *a = (int*)new Base;
	cout << a[0] << " " << a[1] << endl;					// 3775284 10	 (Base클래스정보  x)

	int *b = (int*)new Derived;
	cout << b[0] << " " << b[1] << " " << b[2] << endl;		// 3775296 10 20 (Derived클래스정보 x  y)

	int *c = (int*)new Derived;
	cout << c[0] << " " << c[1] << " " << c[2] << endl;		// 3775296 10 20 (Derived클래스정보  x  y)
			
	// => 맨처음에 포인터[0]에 찍히는 클래스정보를 담는 포인터는 가상함수를 가지는 다형클래스를 상속했을 시에만 만들어진다 ***
																
}