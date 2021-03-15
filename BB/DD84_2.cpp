/*
다형클래스(가상함수가 있는 클래스)를 상속받아야만 
상속받은 자식클래스들 동적할당시에 앞에 클래스정보를 담은 4byte짜리(?)포인터를 붙여준다. RTTI로 런타임도중 객체의 실제 클래스타입을 알기위해
부모클래스가 다형클래스이여야만 함 !!!(가상함수 1개이상 !!) 아니면 포인터에 클래스정보 없어서 RTTI불가, dynamic_cast불가

dynamic_cast는 RTTI 작업을 거쳐야하기 때문에 성능측면에서는 별로 좋지않다.
런타임 도중에 실제타입이 무엇인지 알아오고 형변환하고자하는 타입과 매치해보고 등등.. 
부수적인 일을 많이 해야해서 클래스 설계시에 사용을 지양한다

클래스 설계 구조를 어떻게 바꾸면 dynamic_cast를 사용하지 않고 main에서 
'만약 직사각형일 경우에만, 대각선 길이도 출력' 이 가능할지 생각해보자 (차후에 종합문제에서 다룰 예정)
*/

#include <iostream>
#include <math.h>

using namespace std;

class Shape {
public:
	virtual double GetArea() const = 0;
	virtual void Resize(double k) = 0;
};

class Circle : public Shape {
public:
	Circle(double r) : r(r) {}
	double GetArea() const {
		return r * r * 3.14;
	}
	void Resize(double k) {
		r *= k;
	}
private:
	double r;
};

class Rectangle : public Shape {
public:
	Rectangle(double a, double b) : a(a), b(b) {}
	double GetArea() const {
		return a * b;
	}
	void Resize(double k) {
		a *= k;
		b *= k;
	}
	double GetDiag() const {
		return sqrt(a * a + b * b);
	}
private:
	double a, b;
};

int main() {
	Shape *shapes[] = { new Circle(1), new Rectangle(1, 2) };	// 포인터배열. 배열자체는 동적할당x, 각칸들만 동적할당o
	// shapes[i] 자체가 포인터

	cout << sizeof(Shape) << endl;
	cout << sizeof(shapes) << endl;
	cout << sizeof(Circle) << endl;
	cout << sizeof(Rectangle) << endl;	// 4 8 16 24 ... 흠 왜 ㅠ?

	for (int i = 0; i < 2; i++) {
		// 도형의 넓이
		// 만약 직사각형일 경우에만, 대각선 길이도 출력
		cout << "도형의 넓이 : " << shapes[i]->GetArea() << endl;
		
		Rectangle *r = dynamic_cast<Rectangle*>(shapes[i]);
		// 모든 shapes[i]를 Rectangle *r포인터로 형변환을 시도(dynamic_cast) 
		//: 컴파일타임에는 shapes[i]가 실제로 Circle인지 Rectangle인지 알수x. 
		//  따라서 shapes[i]가 형변환되면(실제로Rectangle이면) 형변환하고, 안되면(실제로Circle이면) r에 NULL반환

		// static_cast<>() 사용하면 무조건 컴파일은 성공한다. shapes[i]가 실제로 Circle, Rectangle인지 모르지만 무조건 Rectangle이라고 
		// 가정하고 형변환 시켜서 넘긴다. 무.조.건. 그러나 이후 런타임시 에러나 문제는 개발자가 알아서 ^^ 
		if (r != NULL) {
			// shapes[i]가 실제로 Rectangle객체여서 형변환 성공했으면 
			cout << "대각선의 길이 : " << r->GetDiag() << endl;
		}
	}

	for (int i = 0; i < 2; i++) {
		delete shapes[i];
	}
}