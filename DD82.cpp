/* ��Ӱ� ������

��ӿ����� ����ȯ(1) - ��ĳ���� Upcasting : �ڽ�Ŭ���� ������ -> �θ�Ŭ���� ������ (������)

C++ STL�� ����ϸ� ���⽺������ ���� ���� �� �ִ�
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
	//FlyingAnimal *a = new FlyingAnimal[10];	// zpos�� xpos, ypos�� �з��� ��µȴ�.

	// ��ü �ϳ��� ������ ���� X
	// �׷��� ��ü�� �迭�� �Ǹ� 
	// FlyingAnimal�� �ؼ��ϸ� 3ĭ�� ��ü �Ѱ��� �ǰ� Animal�� �ؼ��ϸ� 2ĭ�� ��ü �Ѱ��� �ȴ�
	// 3ĭ¥�� �迭�� printAnimal���� Animal *a�� �Է¹޾� 2ĭ���� �߸� �ؼ��� �Ǿ� x,y  y,z  z,x  y,z...�̷��� ��µƴ�
	
	// �ذ�å: ������ �迭�� ����Ѵ�

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