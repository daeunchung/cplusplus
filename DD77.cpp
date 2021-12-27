/* �������̵��� ���� ���ε�
override : �켱�ϴ�

java�� C#������ �������ε� ���� X
C++������ �������ε� �Ͼ��

Base, Derived Ŭ���� ��ο� Print()�� �ְ� �������̵��� �Ͼ ��쿡
Base *b = new Derived(); �������� - Base�����ͷ� �ٸ���ü�� ����Ű�� ��������
b�� ���� ����Ű�� �ִ� ��ü�� Ÿ���� �˾Ƴ��°� �����Ƿ� ������ Base b���� ȣ������ => ���� ���ε� 
������ b->Print()�� Base(�θ�) ���� ���ε� ���� => ���� ���ε�
�׶��׶� ���ε� ����� �޶����� => ���� ���ε�
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
	cout << d.a << endl;	// 20 �������� ������ ������ ��������� �θ�Ŭ���� �������� �켱�Ѵ�
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
//Base *b = &d;	// �θ�Ŭ���� �����Ͱ� �ڽ�Ŭ������ ����ų �� �ִ�

int main() {
	Base *b = new Derived();	// �̶��� b�� Base Derived �� ���� ����ؾ��ϴ°� �� Binding �̶�� �Ѵ�
	// (*b).Print(); 
	b->Print();		// Base ? Derived ? => From Base!!!�� ��µȴ� 
	delete b;
}