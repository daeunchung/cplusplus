/*
����Ŭ����(�����Լ��� �ִ� Ŭ����)�� ��ӹ޾ƾ߸� 
��ӹ��� �ڽ�Ŭ������ �����Ҵ�ÿ� �տ� Ŭ���������� ���� 4byte¥��(?)�����͸� �ٿ��ش�. RTTI�� ��Ÿ�ӵ��� ��ü�� ���� Ŭ����Ÿ���� �˱�����
�θ�Ŭ������ ����Ŭ�����̿��߸� �� !!!(�����Լ� 1���̻� !!) �ƴϸ� �����Ϳ� Ŭ�������� ��� RTTI�Ұ�, dynamic_cast�Ұ�

dynamic_cast�� RTTI �۾��� ���ľ��ϱ� ������ �������鿡���� ���� �����ʴ�.
��Ÿ�� ���߿� ����Ÿ���� �������� �˾ƿ��� ����ȯ�ϰ����ϴ� Ÿ�԰� ��ġ�غ��� ���.. 
�μ����� ���� ���� �ؾ��ؼ� Ŭ���� ����ÿ� ����� �����Ѵ�

Ŭ���� ���� ������ ��� �ٲٸ� dynamic_cast�� ������� �ʰ� main���� 
'���� ���簢���� ��쿡��, �밢�� ���̵� ���' �� �������� �����غ��� (���Ŀ� ���չ������� �ٷ� ����)
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
	Shape *shapes[] = { new Circle(1), new Rectangle(1, 2) };	// �����͹迭. �迭��ü�� �����Ҵ�x, ��ĭ�鸸 �����Ҵ�o
	// shapes[i] ��ü�� ������

	cout << sizeof(Shape) << endl;
	cout << sizeof(shapes) << endl;
	cout << sizeof(Circle) << endl;
	cout << sizeof(Rectangle) << endl;	// 4 8 16 24 ... �� �� ��?

	for (int i = 0; i < 2; i++) {
		// ������ ����
		// ���� ���簢���� ��쿡��, �밢�� ���̵� ���
		cout << "������ ���� : " << shapes[i]->GetArea() << endl;
		
		Rectangle *r = dynamic_cast<Rectangle*>(shapes[i]);
		// ��� shapes[i]�� Rectangle *r�����ͷ� ����ȯ�� �õ�(dynamic_cast) 
		//: ������Ÿ�ӿ��� shapes[i]�� ������ Circle���� Rectangle���� �˼�x. 
		//  ���� shapes[i]�� ����ȯ�Ǹ�(������Rectangle�̸�) ����ȯ�ϰ�, �ȵǸ�(������Circle�̸�) r�� NULL��ȯ

		// static_cast<>() ����ϸ� ������ �������� �����Ѵ�. shapes[i]�� ������ Circle, Rectangle���� ������ ������ Rectangle�̶�� 
		// �����ϰ� ����ȯ ���Ѽ� �ѱ��. ��.��.��. �׷��� ���� ��Ÿ�ӽ� ������ ������ �����ڰ� �˾Ƽ� ^^ 
		if (r != NULL) {
			// shapes[i]�� ������ Rectangle��ü���� ����ȯ ���������� 
			cout << "�밢���� ���� : " << r->GetDiag() << endl;
		}
	}

	for (int i = 0; i < 2; i++) {
		delete shapes[i];
	}
}