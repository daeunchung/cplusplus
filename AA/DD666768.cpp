/*
void pointer : 주소값만 저장, 저장된데이터의 용량과 타입은 저장X . 
			따라서 내부의 값을 변경할 수 없음 . 완전한 개체형식에 대한 포인터이어야 한다 
			
char *strData를 출력하는 과정에서 cout << strData ; 하면 컴파일러가 
strData가 문자열인지 char*포인터인지 알수없다. 따라서 문자열로 인식. strData가 NULL이면 에러발생
cout << (void*)strData ; 와 같이 작성하여 포인터값을 출력

char *ptr = strData;
*ptr = 'A';
void *ptr = strData;
*ptr = 'A';				// ERROR : 식이 완전한 개체 형식에 대한 포인터여야 합니다. 
*/

#include <iostream>		// <string.h>를 내포 
#include <string.h>
using namespace std;

class String {
public:
	// 기본생성자 
	String(){
		cout << "String() 생성자 호출" << endl;
		strData = NULL;									// 0을 macro로 NULL 
		len = 0;
	} 
	
	// 생성자 오버로딩 
	String(const char *str){
		cout << "String(const char*) 생성자 호출" << endl;
//		strData = str;									// 얕은복사라서 안된다 메모리할당 해줘야함
		len = strlen(str);
		strData = new char[len+1];
		cout << "strData 할당 : " << (void*)strData << endl;
//		char* strcpy(char *_Dest, const char *_Source){}
		strcpy(strData, str); 							// 깊은복사 
	}
	
	// 복사생성자 
	String(const String &rhs){
		cout << "String(String &rhs) 생성자 호출" << endl;
//		strData = rhs.strData;							// 포인터라서 문제발생 
		strData = new char[rhs.len+1]; 					// 메모리 먼저 할당 
		cout << "strData 할당 : " << (void*)strData << endl;
//		char* strcpy(char *_Dest, const char *_Source){}
		strcpy(strData, rhs.strData); 					// 깊은복사 
		len = rhs.len;									// 포인터X int라서 깊은복사 
	}
	
	// 소멸자 
	~String(){
		cout << "~String() 소멸자 호출" << endl;
		delete[] strData;
		cout << "strData 해제됨 : " << (void*)strData << endl;
		strData = NULL;									// 관습 
	}
	
	// 대입연산자 오버로딩 
	String &operator=(const String &rhs){ // String operator=(const String rhs) 입력받고 반환받을때 각각 일어나는 객체로의 복사를 생략하기 위해 참조변수로 받고 반환 
		if(this != &rhs){	// 자기자신에게 대입하는 경우를 방지하기 위하여 
			// 새로생성하는게 아니고 기존에 있던 메모리에 대입하는 거라서 메모리 FLUSH 필요
			delete[] strData; 								// strData가 NULL이면 애초에 delete[]가 아무동작X 
			cout << "strData 메모리삭제" << endl;
			strData = new char[rhs.len+1]; 					// 메모리 먼저 할당 
			cout << "strData 할당 : " << (void*)strData << endl;
			strcpy(strData, rhs.strData); 					// 깊은복사 
			len = rhs.len;	
		} 
		return *this;
		// this : 함수가 실행될때 함수에 속해있는 객체의 주소값.
		// *this : 객체 그 자체 
	}
	
	char *GetStrData() const {
		return strData;
	}
	int GetLen() const {
		return len;
	}
private:
	char *strData;
	int len;
};

int main(){
	String s1("안녕");
	String s2(s1);		// 복사생성자 호출로 객체 생성 
//	String s2 = s1;		// 위와 동일한 표현 (c++에서는) 
	
	String s3;			// 객체 생성만. 기본생성자 
//	s3 = s1;			// 대입연산자 assignment operator 오버로딩 (=연산자도 반환값이 있으니 좌<-우 로 넣어주는것) 
	s3.operator=(s1);	// 위와 동일한 표현 (s3 = s1 표현에서 = s1을 멤버메서드로 이해)
	
	s3.operator=(s3);	// 이렇게 수행되면 메모리삭제하고 새메모리 파서 그 쓰레기값을 쓰레기값으로 복사하면 ERROR 
						// 이를 막아줄 수 있어야한다. 조건 추가해야함 
	
	cout << s1.GetStrData() << endl;
	cout << s2.GetStrData() << endl;
	cout << s3.GetStrData() << endl;
} 


