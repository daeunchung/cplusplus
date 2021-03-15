#include <iostream>
using namespace std;

// 0. 다음 프로그램의 실행 결과는?

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

// 1. 빈칸 채우고, 출력 결과 예측
// (&r, &rp와 같은 참조변수는 사실 메모리상에 존재하지만 사용자가 접근할수 없기때문에 
// 문제풀때 그림상에 메모리를 그리지 않고 다른변수를 포인팅만 해주게 그려서 푼다) 

int main(){
	int a=10, b=20, c=30;
	int *p = &a;
	int &r = b;
	int **pp = &p;	// p라는 포인터 가리키는 더블 포인터 pp (24강) 
	int* (&rp) = p;	// p라는 포인터 가리키는 레퍼런스 변수 rp (51강) - 가리키고자하는 타입이 int* 
	
	r = c / *p;		// b = 3;
	rp = &c;		// rp 가 p를 가리키기  때문에 p = &c;가 된다 *** 아주중요 *** 
	**pp = 40;		// a = 40;
	*p = 50;		// a = 50;
	*pp = &a;		// 다시 p = &a; 
	*rp = 60;
	
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	cout << "c : " << c << endl;
	cout << "*p : " << *p << endl;
	cout << "r : " << r << endl;
	cout << "**pp : " << **pp << endl;
	cout << "*rp : " << *rp << endl;
} 
