#include <iostream>
using namespace std;

// 0. ���� ���α׷��� ���� �����?

//int main(){
//	char str[] = "Hello, World!";
//	char *p_str = str;
//	
//	cout << str << endl;
//	cout << *str << endl;
//
//	cout << p_str << endl;
//	cout << *p_str << endl;
//} 

// 1. ��ĭ ä���, ��� ��� ����
// (&r, &rp�� ���� ���������� ��� �޸𸮻� ���������� ����ڰ� �����Ҽ� ���⶧���� 
// ����Ǯ�� �׸��� �޸𸮸� �׸��� �ʰ� �ٸ������� �����ø� ���ְ� �׷��� Ǭ��) 

int main(){
	int a=10, b=20, c=30;
	int *p = &a;
	int &r = b;
	int **pp = &p;	// p��� ������ ����Ű�� ���� ������ pp (24��) 
	int* (&rp) = p;	// p��� ������ ����Ű�� ���۷��� ���� rp (51��) - ����Ű�����ϴ� Ÿ���� int* 
	
	r = c / *p;		// b = 3;
	rp = &c;		// rp �� p�� ����Ű��  ������ p = &c;�� �ȴ� *** �����߿� *** 
	**pp = 40;		// a = 40;
	*p = 50;		// a = 50;
	*pp = &a;		// �ٽ� p = &a; 
	*rp = 60;
	
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	cout << "c : " << c << endl;
	cout << "*p : " << *p << endl;
	cout << "r : " << r << endl;
	cout << "**pp : " << **pp << endl;
	cout << "*rp : " << *rp << endl;
} 
