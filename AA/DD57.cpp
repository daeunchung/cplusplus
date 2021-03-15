#include <iostream>
using namespace std;

class Time{
public:
	// 변수 초기화 목록 예시 m(m_), s(s_)
	Time() : h(0), m(0), s(0){ }
	
	// 생성자 위임 
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
