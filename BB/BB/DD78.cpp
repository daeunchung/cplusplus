/*
가상함수와 동적 바인딩

컴파일 : 프로그램을 만드는 시기
런타임 : 프로그램이 실행되는 시기
*/
#include <iostream>
using namespace std;

class Weapon {
public:
	Weapon(int power) : power(power) {
		cout << "Weapon(int)" << endl;
	}
	virtual void Use() {	// 가상 함수 virtual : 가상의 (함수가 호출이 될수도 안될수도 있다는 뜻을 내포한다)
		cout << "Weapon::Use()" << endl;
	}
protected:
	int power;
};

class Sword : public Weapon {
public:
	Sword(int power) : Weapon(power) {
		cout << "Sword(int)" << endl;
	}
	void Use() { // 오버라이딩
		cout << "Sword::Use()" << endl;
		Swing();
	}
private:
	void Swing() {
		cout << "Swing sword." << endl;
	}
};

class Magic : public Weapon {
public:
	Magic(int power, int manaCost) : Weapon(power), manaCost(manaCost) {
		cout << "Magic(int, int)" << endl;
	}
	void Use() { // 오버라이딩
		cout << "Magic::Use()" << endl;
		Cast();
	}
private:
	void Cast() {
		cout << "Cast magic." << endl;
	}
	int manaCost;
};

int main() {
	Sword mySword(10);
	Magic myMagic(15, 7);

	mySword.Use();
	myMagic.Use();

	// 부모클래스 함수가 virtual 키워드 없이 일반 함수이면
	// 정적 바인딩으로 인해 currentWeapon은 Weapon객체포인터이기에 currentWeapon->Use(); 시에 무조건 Weapon의 함수가 실행된다.

	// 부모클래스 함수에 함수가 virtual 키워드가 붙은 가상함수이면 
	// 프로그램을 만드는 시점에는 알 수 없으니까 프로그램이 실행되는 시점에서 결정하게 끔 결정을 미룬다.
	// 프로그램 실행되는 시점에 보면
	// currentWeapon = &mySword; 로 부모클래스 포인터에 Sword 객체 mySword를 넣어주었기에 
	// currentWeapon->Use(); 가 실행되는 시점에서는 포인터가 어떤 객체를 가리키는지 정확히 알 수 있다.

	// virtual 안붙어있으면 포인터가 어떤객체를 가리키는지 알기 어려워 무조건 부모객체 꺼로 호출		 => 정적 바인딩
	// virtual 키워드 붙어있으면 호출될 함수 정하는 일(Binding)을 실행되는 시점에 결정하도록 미룬다	 => 동적 바인딩

	// 결 론 :
	// 부모클래스의 가상함수를 자식클래스에서 오버라이딩 하면 동적 바인딩이 일어난다. 
	// 부모클래스의 포인터를 통해서 오버라이딩된 함수를 호출하면 자식클래스에서 오버라이딩한 함수가 실행된다
	Weapon *currentWeapon;

	currentWeapon = &mySword;
	currentWeapon->Use();		// 컴파일시점에서는 currentWeapon이 누구를 가리키는지 알기 힘드나, 프로그램 실행시점에서는 쉽게 알 수 있다
	currentWeapon = &myMagic;
	currentWeapon->Use();

}