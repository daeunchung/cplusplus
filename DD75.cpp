/*
상속 : 자식은 부모에 포함된다.

접근 제어 
public		외부접근o 자식클래스o
protected	외부접근x 자식클래스o
private		외부접근x 자식클래스x

class Derived : public Base {} 99% 부모public->자식public     부모protected->자식protected
class Derived : protected Base {}  부모public->자식protected  부모protected->자식protected
class Derived : private Base {}    부모public->자식private    부모protected->자식private
*/

#include <iostream>

using namespace std;

class Base {
public:
	int bPublic;
protected:
	int bProtected;
private:
	int bPrivate;
};

class Derived : public Base {
public:
	int dPublic;

	int DFunc() {
		bPublic = 1;
		bProtected = 2;
		//bPrivate = 3;
		dPublic = 4;
		dPrivate = 5;
	}

private:
	int dPrivate;
};

int main() {
	Base b;
	Derived d;

	b.bPublic = 1;
	//b.bProtected = 2;
	//b.bPrivate = 3;

	d.bPublic = 1;
	//d.bProtected = 2;
	//d.bPrivate = 3;
	d.dPublic = 4;
	//d.dPrivate = 5;
}