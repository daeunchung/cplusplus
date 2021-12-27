/*
 3.3 Operator Overloading
 		�Լ� �����ε��� ū���� X 
 		���� ��� : 1. friend�� �̿��� �ܺ��Լ� ����  2. ����Լ��� �����ϴ� ���
     This Pointer ��ü�ڽ��� ����Ű�� ������. ��� ����Լ��� ������ ���� (static ����Լ� ����) 
*/

class Complex	// ���Ҽ� 
{
private:
	double m_real, m_imag;
public:
	Complex() { m_real = m_imag = 0.0; }
	Complex operator+(Complex c);
	// operator+(this, Complex c) �̰� this�� �����Ǿ� �ִٰ� �����ϸ� �ȴ�. this�� operator+�� ȣ���ϴ� ��ü�� �ǹ���. 
	friend Complex operator-(Complex c1, Complex c2);
// ****** friend Ű���� : Ŭ�����ܺ��� �Լ������� private�̳� protected�� ��ȣ�� �κп� ������ �����ϴ�.****** 
 } 
 
Complex Complex::operator+(Complex c)	// Complex:: class Complex ������ ����Լ����� �ǹ� 
{
	Complex c3;
 	c3.m_real = m_real + c.m_real;
 	c3.m_imag = m_imag + c.m_imag;
}
 
Complex operator-(Complex c1, Complex c2)	
// �ܺ��Լ��̱� ������ Complex::���� �Լ��� �ٷν��ְ� friend Ű����� private ������ m_real, m_imag ���ٰ��� 
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
	�Լ��� ǥ���ϸ� 
	c3 = c1.operator+(   c2);	
	operator+�� �Լ���� ���� c1��ü�� ����Լ��̱⿡ ȣ��Ǵ� this�� c1�̵ȴ�.
	��, c1�� operator+ �Լ��� c2���ڸ� ���� ���� c3�� ���� 
	
	c3 = operator-(c1, c2);
	�ܺ��� �Լ� operator-�� c1, c2���ڸ� ���� ���� c3�� ���� 
	*/
} 
