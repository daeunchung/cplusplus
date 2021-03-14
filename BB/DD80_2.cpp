#include <iostream>
using namespace std;

const double PI = 3.141592653589793;

/*
추상클래스 존재의 목적 : 도형(Shape클래스)을 상속받는다면 ( 부모 클래스가 도형이라면 )
자식클래스는 반드시 GetArea, Resize를 해야한다 . ( 반드시 상속받은 추상 클래스의 순수가상함수를 구현해야한다 )

즉, 추상 클래스는 틀을 제공한다
*/
class Shape {
public:
	virtual double GetArea() = 0;
	virtual void Resize(double f) = 0;
};

class Circle : public Shape {
public:
	Circle(double r) : r(r) {}

	double GetArea() {
		return PI * r * r;
	}

	void Resize(double f) {
		r *= f;
	}
private:
	double r;
};

class Rectangle : public Shape {
public:
	Rectangle(double a, double b) : a(a), b(b) {}

	double GetArea() {
		return a * b;
	}

	void Resize(double f) {
		a *= f;
		b *= f;
	}
private:
	double a, b;
};

int main() {
	Shape *shapes[] = {
		new Circle(10),
		new Rectangle(20, 30)
	};

	for (Shape *s : shapes) {
		s->Resize(2);
		cout << s->GetArea() << endl;
	}
	// 메모리해제 반드시..
	for (Shape *s : shapes) {
		delete s;
	}
}