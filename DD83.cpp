/* ��Ӱ� ������

��ӿ����� ����ȯ(2) - �ٿ�ĳ���� Downcasting : �θ� -> �ڽ�

��� 1) static_cast		�����Ͻð� ���� �Ͼ�� ���� ����ȯ
	������ �� : ��ĳ����, �ٿ�ĳ����, double -> int / int -> double ���
	���ո��� ����ȯ�� �����ϱ� ���� ����

��� 2) dynamic_cast


*/

#include <iostream>
using namespace std;

class Base {
public:
	int a = 1;
};

class Drv1 : public Base {
public:
	/* f()�޼���� class�ȿ� ���ǵǾ������� ������ � ��ü�ȿ� ���ԵǾ��ִ� ��ü�� �ƴϴ�
	�ٸ� ���� ����Ǿ��ְ� � ��ü�� f()�� ȣ���ؾ��ϴ����� ���� ������ this �����ͷ� �Ѿ���� ��
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
	//b->Drv1Ŭ������ ����,�޼���;	// �Ұ��� (�������ε�, BaseŬ��������,�޼��常 ->�� ���ٰ���)
	//b->a;							// ����

	//Drv1 *d1 = b;					// ������ �ٿ�ĳ���� �Ұ���.	C++ ������ �ڽ�Ŭ���� �����Ϳ� �θ�Ŭ���� ������ ������ ����
	//Drv1 *d1 = (Drv1*)b;			// ����� �ٿ�ĳ���� ����.	�ּҰ��� ����, �ڷ����� ����

	//int *a = new int(5);
	//Drv1 *d1 = (Drv1*)a;	// ���� �ȵǴ� ���δٸ������ͳ��� ����ȯ int -> Drv1. �ּҰ��� �ּҰ��̱⿡ ErrorX, ������O => ������ ���� �ʿ�
	// ������ �������� ���� ������ �߿� �ո����� ������ ������ �ʿ��ϴ� => static cast
	//Drv1 *d1 = static_cast<Drv1*>(a);	// ���� : static_cast<��>(��); ���� ������ ����ȯ�ϰڴ� (������ ��Ӱ���� ok  �ƴϸ� ERROR)

	Drv2 *d2 = static_cast<Drv2*>(b);	// b�� Drv1�ε� �����Ͽ���X ... ;; �̰� ��¿ �� ���� ���α׷��Ӱ� �����ؾ��ϴ� �κ��̴�
	// b�� ������ Drv1�ε� �����Ϸ��� Base��� �����ϰ� static_cast<Drv2*>(b)�� �����Ų��
	d2->f();
	
	delete b;


	// �׷��ٸ� b�� ������ ����Ű�� ��üŸ���� ��Ÿ�ӿ� �˼� �ִ� ����� ������ ? => dynamic cast
}