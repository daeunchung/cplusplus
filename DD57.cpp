#include <iostream>
using namespace std;

class Time{
public:
	// ���� �ʱ�ȭ ��� ���� m(m_), s(s_)
	Time() : h(0), m(0), s(0){ }
	
	// ������ ���� 
	Time(int s_) : Time(){
		s = s_;
	}
	Time(int m_, int s_) : Time(s_){
		m = m_;
	}
	Time(int h_, int m_, int s_) : Time(m_, s_){
		h = h_;
	}
	
	int h, m, s; 
}; 
int main(){
	Time t1;
	Time t2(5);
	Time t3(3, 16);
	Time t4(2, 42, 15);
}
