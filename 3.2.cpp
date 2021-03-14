/*
 String class : c++ string의 문제점과 String class의 잇점
 생성자 : 디폴트생성자(배열생성시), 복제생성자
 제거자 : 할당한 리소스 해제용, 인자/리턴값 X
  		  계승이 사용되는 클래스인 경우 제거자는 virtual이어야함.
		  base class 포인터로 대입된 derived class인 경우 virtual이 아니면 base class 해당부분의 destructor만 호출된다.
		   
 계승과 생성자 : Base클래스의 생성자를 호출하는 방법
  - DerivedClass(Args) : BaseClass(Args) {body}  // 부모클래스생성자 쓰고 추가로 더 넣어줄 부분을 {body}에 작성
   
 복제생성자 (Copy Initializer Constructor) 
 : 같은 타입의 객체로부터 새로운 객체를 생성 X::X(const X&) 
 복제생성자가 사용되는 경우 1. 다른객체로부터 만들어질때 2. 객체를 함수의 인자로 넘길때 3. 함수에서 객체를 리턴할때 
 
 shallow copy vs deep copy
 Operator Overloading 연산자 중복정의, 연산자의 우선순위와 결합순서
 String 클래스가 제공하는 함수들과 사용법 
 
 Storage Class : 기억부류 
  c++에서 변수들이 생성되는 위치가 크게 3가지 있다. 생성자의 위치에 따라 변수의 생존기간
  life time이 정해짐 
 - 자동변수 (Automatic Variables) : 정의시 생성, 블럭이 끝날때 제거. STACK : reentrant재진입가능
 - 정적변수 (Static Variables) : 프로그램 시작시 생성, 프로그램 끝날때 제거. DATA SEGMENT 에서 할당
 - 동적변수 (Dynamic Variables) : new, delete, HEAP에 
 
주의 ! local variable과 global variable은 life time과는 다른 이야기.
local은 정의된 블럭안에서만 ,  어디에서나 접근 가능한 global 
변수가 정의되는 위치, 생성되는방법(static, new).. 에 따라 Storage Class가 정해진다. 
*/


// Storage Class 의 예
#include <stdio.h>
int global;									// static
void main(){
	static int staticvar = 10;				// main밖에서 접근못하는 static 
	
	char* dynamic = new char[10];			// dynamic
	// do something
	delete[] dynamic;
	
	int local1 = 0;							// auto(local)
	if(local1 == 0){
		int local2;							// auto(local)
		local2 = 0;
	}
	// do something
} 
