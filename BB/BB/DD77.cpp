/* 오버라이딩과 정적 바인딩
override : 우선하다

java나 C#에서는 정적바인딩 거의 X
C++에서는 정적바인딩 일어난다

Base, Derived 클래스 모두에 Print()가 있고 오버라이딩이 일어난 경우에
Base *b = new Derived(); 했을때에 - Base포인터로 다른객체를 가리키고 있을때에
b가 현재 가리키고 있는 객체의 타입을 알아내는게 어려우므로 무조건 Base b꺼로 호출하자 => 정적 바인딩 
무조건 b->Print()가 Base(부모) 꺼로 바인딩 하자 => 정적 바인딩
그때그때 바인딩 결과가 달라진다 => 동적 바인딩
*/
#include <iostream>
using namespace std;

/* ex1
class Base {
public:
	//Base() : a(10) {}
	int a = 10;
	void Print() {
		cout << "From Base!!!" << endl;
	}
};

class Derived : public Base {
public:
	int a = 20;
	void Print() {
		cout << "From Derived!!!" << endl;
	}
};

int  main() {
	Base b;
	Derived d;

	cout << b.a << endl;
	cout << d.a << endl;	// 20 변수명이 같으면 고유의 멤버변수가 부모클래스 변수보다 우선한다
	cout << d.Base::a << endl;
	cout << d.Derived::a << endl;

	d.Print();
	d.Base::Print();
	d.Derived::Print();
}
*/

// ex2
class Base {
public:
	void Print() {
		cout << "From Base!!!" << endl;
	}
};

class Derived : public Base {
public:
	void Print() {
		cout << "From Derived!!!" << endl;
	}
};

class Derived2 : public Base {

};

//int a;
//char *p;
//p = &a;	//ERROR

//Derived d;
//Base *b = &d;	// 부모클래스 포인터가 자식클래스를 가리킬 수 있다

int main() {
	Base *b = new Derived();	// 이때에 b를 Base Derived 중 뭐로 취급해야하는가 를 Binding 이라고 한다
	// (*b).Print(); 
	b->Print();		// Base ? Derived ? => From Base!!!가 출력된다 
	delete b;
}