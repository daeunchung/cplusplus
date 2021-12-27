/*
static_cast : ����(������Ÿ��)
dynamic_cast : ����(��Ÿ��)

C++ ���� virtual�� ���� ���ε��� Ȱ���ϱ� ���ؼ��� RTTI�� �ʿ��ϴ�. �� RTTI�� ����ؼ� dynamic_cast�� �ϴ� ��
RTTI (Run Time Type Information/Identification)

C++���� �ΰ��� Ŭ���� 1)�����Լ��� ����Ŭ����		2)�����Լ��� �ϳ��� �ִ�Ŭ���� (���� Ŭ����)

BaseŬ�����κ��� DerivedŬ������ dynamic_cast�� ���ְ� ������ BaseŬ������ �ݵ�� virtual�����Լ��� �Ѱ��̻� ���Ե� ���� Ŭ�������� �Ѵ�
����Ŭ�������߸� RTTI�� �����ؼ� dynamic_cast�� �����ϰ� ���ֱ� ����
*/
#include <iostream>
using namespace std;

class Base {
public:
	virtual void f(){}
	int x = 10;
};

class Derived : public Base {
public:
	void f(){}
	int y = 20;
};
 
int main() {
	cout << sizeof(Base) << endl;		// BaseŬ���� virtual�Լ� f()������ ������ 4byte(������) + 4byte(int x) // 8
	cout << sizeof(Derived) << endl;	// 4byte(������) + 4byte(int x) + 4byte(int y)						  // 12

	int *a = (int*)new Base;
	cout << a[0] << " " << a[1] << endl;					// 3775284 10	 (BaseŬ��������  x)

	int *b = (int*)new Derived;
	cout << b[0] << " " << b[1] << " " << b[2] << endl;		// 3775296 10 20 (DerivedŬ�������� x  y)

	int *c = (int*)new Derived;
	cout << c[0] << " " << c[1] << " " << c[2] << endl;		// 3775296 10 20 (DerivedŬ��������  x  y)
			
	// => ��ó���� ������[0]�� ������ Ŭ���������� ��� �����ʹ� �����Լ��� ������ ����Ŭ������ ������� �ÿ��� ��������� ***
																
}