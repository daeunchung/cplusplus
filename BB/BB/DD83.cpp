/* 상속과 다형성

상속에서의 형변환(2) - 다운캐스팅 Downcasting : 부모 -> 자식

방법 1) static_cast		컴파일시간 내에 일어나는 정적 형변환
	가능한 일 : 업캐스팅, 다운캐스팅, double -> int / int -> double 등등
	불합리한 형변환을 방지하기 위한 수단

방법 2) dynamic_cast


*/

#include <iostream>
using namespace std;

class Base {
public:
	int a = 1;
};

class Drv1 : public Base {
public:
	/* f()메서드는 class안에 정의되어있지만 실제로 어떤 객체안에 포함되어있는 실체는 아니다
	다른 곳에 저장되어있고 어떤 객체의 f()를 호출해야하는지에 대한 정보가 this 포인터로 넘어오는 것
	*/
	void f() {
		cout << "Drv1::f()" << endl;
		cout << b << endl;
	}
private:
	float b = 3.14;
};

class Drv2 : public Base {
public:
	void f() {
		cout << "Drv2::f()" << endl;
		cout << c << endl;
	}
private:
	int c = 3;
};



int main() {
	Base *b = new Drv1;
	//b->Drv1클래스의 변수,메서드;	// 불가능 (정적바인딩, Base클래스변수,메서드만 ->로 접근가능)
	//b->a;							// 가능

	//Drv1 *d1 = b;					// 묵시적 다운캐스팅 불가능.	C++ 에서는 자식클래스 포인터에 부모클래스 포인터 대입을 금지
	//Drv1 *d1 = (Drv1*)b;			// 명시적 다운캐스팅 가능.	주소값은 유지, 자료형만 변경

	//int *a = new int(5);
	//Drv1 *d1 = (Drv1*)a;	// 말도 안되는 서로다른포인터끼리 형변환 int -> Drv1. 주소값은 주소값이기에 ErrorX, 컴파일O => 방지할 수단 필요
	// 강제로 실행하지 말고 컴파일 중에 합리성을 따져줄 수단이 필요하다 => static cast
	//Drv1 *d1 = static_cast<Drv1*>(a);	// 문법 : static_cast<ㄴ>(ㄱ); ㄱ을 ㄴ으로 형변환하겠다 (ㄱㄴ이 상속관계면 ok  아니면 ERROR)

	Drv2 *d2 = static_cast<Drv2*>(b);	// b는 Drv1인데 컴파일에러X ... ;; 이건 어쩔 수 없고 프로그래머가 유의해야하는 부분이다
	// b는 실제로 Drv1인데 컴파일러는 Base라고 간주하고 static_cast<Drv2*>(b)를 통과시킨다
	d2->f();
	
	delete b;


	// 그렇다면 b가 실제로 가리키는 객체타입을 런타임에 알수 있는 방법은 없을까 ? => dynamic cast
}