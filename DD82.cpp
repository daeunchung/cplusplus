/* 상속과 다형성

상속에서의 형변환(1) - 업캐스팅 Upcasting : 자식클래스 포인터 -> 부모클래스 포인터 (묵시적)

C++ STL을 사용하면 번잡스러움을 많이 줄일 수 있다
*/  

#include <iostream>
using namespace std;

class Animal {
public:
	float xpos = 1;
	float ypos = 2;
};

class FlyingAnimal : public Animal {
public:
	float zpos = 3;
};

void printAnimals(Animal **a, int n) {	
	for (int i = 0; i < n; i++) {
		cout << "(" << a[i]->xpos << ", " << a[i]->ypos << ")" << endl;
	}
}

int main() {
	//FlyingAnimal *a = new FlyingAnimal[10];	// zpos가 xpos, ypos로 밀려서 출력된다.

	// 객체 하나만 있으면 문제 X
	// 그러나 객체가 배열이 되면 
	// FlyingAnimal로 해석하면 3칸이 객체 한개가 되고 Animal로 해석하면 2칸이 객체 한개가 된다
	// 3칸짜리 배열이 printAnimal에서 Animal *a로 입력받아 2칸으로 잘못 해석이 되어 x,y  y,z  z,x  y,z...이렇게 출력됐다
	
	// 해결책: 포인터 배열을 사용한다

	Animal **a = new Animal*[10];
	for (int i = 0; i < 10; i++) {
		a[i] = new FlyingAnimal;
	}
	printAnimals(a, 10);
	for (int i = 0; i < 10; i++) {
		delete a[i];
	}
	delete[] a;
}