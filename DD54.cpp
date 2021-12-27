/*
 ���������� : private, protected, public 
 C��� struct �� C++ struct �� �� �� ��.  (C����ü + ��û�������) 
 class : C++ struct�� ���̴� �� �Ѱ��� (������������ default���� public, private) 

 Ŭ���� = �ڷ� ���� + �ڷ� ó�� = ���� + �Լ�
 Ŭ����(Ÿ��) : Ư���� �뵵�� �����ϱ� ���� ������ �Լ��� ��� �� Ʋ(�ڷ���)
 ��ü(������Ʈ) : �� Ʋ�� �̿��Ͽ� �� ��ü (����, �޸� ���� ����) 

struct �� �⺻������ public 
private: �� ������(���������� �Ⱦ���) default�� public���� �����ȴ�.
class �±⺻������ private 
private: ��� (���������� �Ⱦ���) default�� private�� �����ȴ�. 

 55��, 56��, 57�� 
 ������: ��� ���� �ʱ�ȭ
 �Ҹ���: �޸� ����
*/

#include <iostream>
using namespace std;

class Complex{	// ���Ҽ� ����� Ŭ���� 
	public:
		Complex() : real(0), imag(0) { }
		
// 		�̷��� ���������� �Ű�������� ����������� ���Խ��൵ ������. �翬�� var1(arg1)���� �ν� 
		Complex(double real, double imag) : real(real), imag(imag) { }
		Complex(double real_, double imag_) : real(real_), imag(imag_) { }
		Complex(){
			real = 0;	imag = 0;
		}
		Complex(double real_ = 0, double imag_ = 0){
//		���������ڿ����� �Ű�������� ����������� �޸��ؾ��Ѵ�. 
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
