// �������� : ��Ŭ���� ȣ���� , �ּҰ���� = �� �ڿ����� �� / �ִ�����

#include <iostream>
using namespace std;
int func(int a, int b) {
//	cout << a << ' ' << b << '\n';
	if (b == 0) return a;
	if (a >= b) return func(b, a % b);
	if (a < b) return func(a, b % a);
	// => no need to swap
}

int main() {
	int a, b;
	cin >> a >> b;
	int gcd = func(a, b);
	int lcm = a * b / gcd;
	cout << gcd << '\n' << lcm << '\n';
	return 0;
}