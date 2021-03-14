/*
68강에서는 얕은복사의 문제점때문에 깊은복사로 바꿔주기
69강에서는 깊은복사를 문제점때문에 얕은복사로 바꿔주기 
	- 이동시맨틱(?) 얕은복사 지원해주는 C++11 새로운컨셉 
	불필요한 깊은복사(메모리생성 & 포인터의 포인팅)가 반복되면 비효율적.
	하나의 메모리를 포인터가 가리키고 끊고 다른 포인터가 가리키고 끊고 또다른 포인터가 가리키고... => 이동된다고 표현
	<이동 시맨틱> 에서 이동생성자, 이동대입연산자 사용하면 얕은복사 가능 
	
	이동 시맨틱을 위해서는 rvalue가 필요하다. 
	
	r-value 등호의 우변에만 쓸수 있는 값이다라는 뜻에서 파생된 단어 . 좌변에 못옴 
	l-value 는 등호의 좌변에 올 수 있고 우변에도 올 수 있다. 
	int a = 5;
	a = 5;
	a = a;
	5 = a; (X) 
	C++ 에서 모든 값은 rvalue 또는 lvalue 인데 우변에만올수있으면rvalue,  좌변우변다올수있으면lvalue 
	
	int f() { return 5; }
	메모리에 어떤값이 저장이 되어있는 경우에 그곳에 대입이 가능하다.
	f() = 1; (X)  
	f()가 반환하는 return값 자체는 임시객체가 맞다.  임시객체는 메모리상에 실제로 저장이 되어있다.
	근데 왜 임시객체에 1을 대입할 수 없는가? 
	=> f()가 rvalue이기 때문 애초에 좌변에 올수없고 메모리상에 저장은 되어있지만 rvalue라서 f()=1; 식이 말이안됨 
	
	lvalue 메모리상에 저장O
	임시객체는 예외적으로 함수가 반환하기에 메모리상에 저장이 되어있지만 반환값에 대입할 수 없기때문에 rvalue이다 
	
*** 결론 : 임시객체는 rvalue이다 ***
	
	String &&r = getName();	// &&r r-value 참조자에 getName()이 반환하는 String임시객체를 참조해줄 수 있다(저장X) 
	r-value 반환값을 눈에보이게 표현하기 위해 r-value참조자를 이용해서 참조해줄 수 있다. 
	

*******************************************************************************************************
	
 return res;구문이 호출될 당시에 res는 lvalue이지만 res가 반환되는 동안에 res는 rvalue로 간주된다. 
 res가 rvalue로 간주되어야 이동생성자 String(String &&rhs){} 가 호출이 된다. ... ㅅㅂ 어려워 
 만약 이함수가 선언이 안되었다면 String(const String &rhs)가 rvalue를 받는다.
 rvalue는 수정할 수 없는 값을 의미
 
 String &rhs 참조타입에 const를 붙여서 바꾸어주면 수정불가능 고정이기때문에 
 rvalue를 받는 전용함수 String(String &&rhs)가 없을 경우에 String(const String &rhs)가 rvalue를 받아준다. "만능"
 그대신 매개변수 타입에 const 안붙여주면 rvalue를 받지 못한다.

 요약: String(String &&rhs){} 가 없을 경우 String(const String &rhs){}가 rvalue를 받아줄 수 있다.
 이유는 const 참조변수라서. 변경X를 보장하기 때문. const 없으면 String(String &rhs)이면 rvalue 못받는다. 

 res가 임시객체로 복사가 되는 과정에서 res는 rvalue로 간주가 되고 String(String &&rhs){}로 받아져서 이동생성자 실행
 
 요약 : 
 lvalue 받을때는 String(const String &rhs){} 복사생성자, String &operator=(const String &rhs){} 복사대입연산자
 rvalue 받을때는 String(String &&rhs){} 이동생성자, 	String &operator=(String &&rhs){} 이동대입연산자 C++11에서 추가된 이동시맨틱 
 (rvalue : 임시객체, 사라지려고하는 함수에서 반환되기 직전의 res같은 객체) 
 
  
*/

#include <iostream>
#include <string.h>
using namespace std;

class String {
public:
	String(){
		cout << "String() : " << this << endl;
		strData = NULL;									
		len = 0;
	} 
	String(const char *str){
		cout << "String(const char*) : " << this << endl;
		len = strlen(str);
		alloc(len);
		strcpy(strData, str);
	}
	// 복사생성자 
	String(const String &rhs){
		cout << "String(const String&) : " << this << endl;
		len = rhs.len;								
		alloc(len);
		strcpy(strData, rhs.strData); 				
	}
	
	// 이동생성자 
	String(String &&rhs){
		// 얕은복사는 소멸자가 무조건 한번만 호출 ! 
		cout << "String(String &&) : " << this << endl; 
		len = rhs.len;
		strData = rhs.strData;
		rhs.strData = NULL;		// 소멸자호출되어 delete[] strData;해줘도 메모리랑 연결이 끊겼기 때문에 에러X 
	}
	
	~String(){
		cout << "~String() : " << this << endl;
		release();
		strData = NULL;									
	}
	
	// 복사 대입 연산자 
	String &operator=(const String &rhs){ 
		cout << "String &operator=(const String&) : " << this << endl;
		if(this != &rhs){	
			release(); 
			len = rhs.len;
			alloc(len);	
			strcpy(strData, rhs.strData); 	
		} 
		return *this;		// *this : 객체그자체, this : 객체주소값 
	}
	
	// 이동 대입 연산자
	String &operator=(String &&rhs){
		cout << "String &operator=(String &&) : " << this << endl; 
		len = rhs.len;
		strData = rhs.strData;
		rhs.strData = NULL;
		return *this; // 연쇄적으로 사용하는 String a = b = c; 문법때문에 객체를 반환 
	}
	 
	char *GetStrData() const {
		return strData;
	}
	int GetLen() const {
		return len;
	}
	void SetStrData(const char *str){		// 이건왜있는건지 잘 모르겠음.. 
		cout << "void SetStrData(const char*) : " << this << ", " << str << endl;
		len = strlen(str);
		alloc(len);
		strcpy(strData, str);
	}
	
private:
	void alloc(int len){
		strData = new char[len+1];
		cout << "strData allocated : " << (void*)strData << endl;
	} 
	void release(){
		delete[] strData;
		if(strData) cout << "strData released : " << (void*)strData << endl;
	}
	char *strData;
	int len;
}; 


String getName(){
	cout << "===== 2 =====" << endl;
	String res("Doodle");
	cout << "===== 3 =====" << endl;
	return res;	 
}
int main(){
	String a;
	cout << "===== 1 =====" << endl;
	a = getName();
	cout << "===== 4 =====" << endl;
} 






/* 콘솔 결과창
 
String() : 0x72fdf0
===== 1 =====
===== 2 =====
String(const char*) : 0x72fe00
strData allocated : 0xb36fe0
===== 3 =====
String(const String&) : ====================================================================
strData allocated : 			나는 왜 ( res-> 임시객체 )복사생성자, 이동생성자 호출부분이 
~String() :	원본res					출력이 안되지.. -> 해결: 이거 DEVC++에서 안되는데 VS에서 정상출력됨. 비주얼스튜디오 사용 ! 
strData released : 문자열주소 ==============================================================
String &operator=(const String&) : 0x72fdf0
strData allocated : 0xb37350
~String() : 0x72fe00
strData released : 0xb36fe0
===== 4 =====
~String() : 0x72fdf0
strData released : 0xb37350

--------------------------------
Process exited after 0.3519 seconds with return value 0
계속하려면 아무 키나 누르십시오 . . .
*/

