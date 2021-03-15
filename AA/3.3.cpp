/*
 3.3 Operator Overloading
 		함수 오버로딩과 큰차이 X 
 		정의 방법 : 1. friend를 이용한 외부함수 정의  2. 멤버함수로 정의하는 방법
     This Pointer 객체자신을 가리키는 포인터. 모든 멤버함수의 숨겨진 인자 (static 멤버함수 제외) 
*/

class Complex	// 복소수 
{
private:
	double m_real, m_imag;
public:
	Complex() { m_real = m_imag = 0.0; }
	Complex operator+(Complex c);
	// operator+(this, Complex c) 이고 this가 생략되어 있다고 생각하면 된다. this는 operator+를 호출하는 객체를 의미함. 
	friend Complex operator-(Complex c1, Complex c2);
// ****** friend 키워드 : 클래스외부의 함수이지만 private이나 protected로 보호된 부분에 접근이 가능하다.****** 
 } 
 
Complex Complex::operator+(Complex c)	// Complex:: class Complex 내부의 멤버함수임을 의미 
{
	Complex c3;
 	c3.m_real = m_real + c.m_real;
 	c3.m_imag = m_imag + c.m_imag;
}
 
Complex operator-(Complex c1, Complex c2)	
// 외부함수이기 때문에 Complex::없고 함수명 바로써주고 friend 키워드로 private 영역의 m_real, m_imag 접근가능 
{
	Complex c3;
	c3.m_real = c1.m_real - c2.m_real;
	c3.m_imag = c1.m_imag - c2.m_imag; 
	return c3;
}

int main(){
	Complex c1, c2, c3;
	
	c3 = c1 + c2;
	c3 = c1 - c2;
	/* 
	함수로 표현하면 
	c3 = c1.operator+(   c2);	
	operator+가 함수라고 보면 c1객체의 멤버함수이기에 호출되는 this는 c1이된다.
	즉, c1의 operator+ 함수에 c2인자를 넣은 값을 c3에 대입 
	
	c3 = operator-(c1, c2);
	외부의 함수 operator-에 c1, c2인자를 넣은 값을 c3에 대입 
	*/
} 
