/*
상속관계에서 생성/소멸자 실행 순서와 가상 소멸자

자식클래스의 생성자가 호출될때 부모클래스이 생성자가 먼저 호출된다. 소멸자는 생성자의 역순
생성자의 목적 자체가 멤버변수들을 초기화 하기 위함이다. 따라서 생성자가 실행되기 전에 멤버변수 먼저 만들어야한다.
멤버변수 먼저 생성되고 생성자가 호출되는 것

순서 : (자식클래스 객체생성시)
	부모클래스 멤버변수
	부모클래스 생성자
	자식클래스 멤버변수
	자식클래스 생성자

가상 소멸자 : 소멸자도 가상함수가 될 수 있다
*/

#include <iostream>
using namespace std;

class Ice {
public:
	Ice() { cout << "Ice()" << endl; }
	~Ice() { cout << "~Ice()" << endl; }
};

class Pat {
public:
	Pat() { cout << "Pat()" << endl; }
	~Pat() { cout << "~Pat()" << endl; }
};

class Bingsoo {
public:
	Bingsoo() { 
		cout << "Bingsoo()" << endl; 
		ice = new Ice;
	}
	virtual ~Bingsoo() { // virtual떼면 부모소멸자 ~Bingsoo() 호출O, 자식소멸자 ~PatBingsoo()호출X
		cout << "~Bingsoo()" << endl; 
		delete ice;
	}

private:
	//Ice ice;	// Ice() -> Bingsoo()
	
	Ice *ice; 
	// 멤버변수를 포인터로 해주면 Bingsoo()생성자 안에서 동적할당이 일어나기 때문에 
	// Ice *ice; 포인터 멤버변수 생성 -> Bingsoo()생성자 호출 -> 생성자 안에서 Ice객체생성을 위한 Ice()생성자 호출
};

class PatBingsoo : public Bingsoo {
public:
	PatBingsoo() { 
		cout << "PatBingsoo ()" << endl; 
		pat = new Pat[10];
	}
	~PatBingsoo() { 
		cout << "~PatBingsoo ()" << endl; 
		delete[] pat;
	}

private:
	Pat *pat;
};

int main() {
	//PatBingsoo *p = new PatBingsoo;
	
	Bingsoo *p = new PatBingsoo;
	// 정적바인딩으로 delete p;실행시 ~Bingsoo()가 호출된다. ~PatBingsoo()가 호출되기 바라면 소멸자를 virtual로 만들어주면 동적바인딩된다
	// 가상소멸자로 만들어주면 delete p; 컴파일실행시에 소멸자가 virtual임을 확인하고 판단을 미루고 소멸자를 동적바인딩하기로 결정
	// 실행시점에서 p가 PatBingsoo객체임을 알고 delete p;로 ~PatBingsoo()를 호출한다 (가상함수->동적바인딩과 같은원리)

	// 예) 프로그램 용량이 커져서 PatBingsoo생성자, 소멸자에서 pat = new Pat[1000000]; 을 해줬는데 소멸자가 호출이 안되어 삭제가 안되면 ? 메모리효율 꽝

	delete p;
}