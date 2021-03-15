/*
 접근지정자 : private, protected, public 
 C언어 struct 와 C++ struct 같 지 않 다.  (C언어구조체 + 엄청많은기능) 
 class : C++ struct와 차이는 딱 한가지 (접근지정자의 default값이 public, private) 

 클래스 = 자료 저장 + 자료 처리 = 변수 + 함수
 클래스(타입) : 특정한 용도를 수행하기 위한 변수와 함수를 모아 둔 틀(자료형)
 객체(오브젝트) : 그 틀을 이용하여 찍어낸 개체 (변수, 메모리 상의 공간) 

struct 는 기본설정이 public 
private: 이 없으면(접근지정자 안쓰면) default가 public으로 설정된다.
class 는기본설정이 private 
private: 없어도 (접근지정자 안쓰면) default가 private로 설정된다. 

 55강, 56강, 57강 
 생성자: 멤버 변수 초기화
 소멸자: 메모리 해제
*/

#include <iostream>
using namespace std;

class Complex{	// 복소수 만드는 클래스 
	public:
		Complex() : real(0), imag(0) { }
		
// 		이러한 문법에서는 매개변수명과 멤버변수명을 같게써줘도 괜찮다. 당연히 var1(arg1)으로 인식 
		Complex(double real, double imag) : real(real), imag(imag) { }
		Complex(double real_, double imag_) : real(real_), imag(imag_) { }
		Complex(){
			real = 0;	imag = 0;
		}
		Complex(double real_ = 0, double imag_ = 0){
//		정석생성자에서는 매개변수명과 멤버변수명을 달리해야한다. 
			real = real_;
			imag = imag_;
		}
		double GetReal(){
			return real;
		}
		void SetReal(double real_){
			real = real_;
		}
		double GetImag(){
			return imag;
		}
		void SetImag(double imag_){
			imag = imag_;
		}
	private:
		double real;
		double imag;
};

int main(){
//	int a = 5;	int a(5);
	Complex c1;
	Complex c2 = Complex(2, 3);
	Complex c3(2, 3);
	Complex c4 = {2, 3};
	Complex c5 = Complex{2, 3};
	Complex c6{2, 3};
} 
