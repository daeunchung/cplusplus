#include <iostream>
#include <string.h>
using namespace std;

class String {
public:
	String() {
		cout << "String() : " << this << endl;
		strData = NULL;
		len = 0;
	}
	String(const char *str) {
		cout << "String(const char*) : " << this << endl;
		len = strlen(str);
		alloc(len);
		strcpy(strData, str);
	}
	// 복사생성자 
	String(const String &rhs) {
		cout << "String(const String&) : " << this << endl;
		len = rhs.len;
		alloc(len);
		strcpy(strData, rhs.strData);
	}

	// 이동생성자 
	String(String &&rhs) {
		// 얕은복사는 소멸자가 무조건 한번만 호출 ! 
		cout << "String(String &&) : " << this << endl;
		len = rhs.len;
		strData = rhs.strData;
		rhs.strData = NULL;		// 소멸자호출되어 delete[] strData;해줘도 메모리랑 연결이 끊겼기 때문에 에러X 
	}

	~String() {
		cout << "~String() : " << this << endl;
		release();
		strData = NULL;
	}

	// 복사 대입 연산자 
	String &operator=(const String &rhs) {
		cout << "String &operator=(const String&) : " << this << endl;
		if (this != &rhs) {
			release();
			len = rhs.len;
			alloc(len);
			strcpy(strData, rhs.strData);
		}
		return *this;		// *this : 객체그자체, this : 객체주소값 
	}

	// 이동 대입 연산자
	String &operator=(String &&rhs) {
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
	void SetStrData(const char *str) {		// 이건왜있는건지 잘 모르겠음.. 
		cout << "void SetStrData(const char*) : " << this << ", " << str << endl;
		len = strlen(str);
		alloc(len);
		strcpy(strData, str);
	}

private:
	void alloc(int len) {
		strData = new char[len + 1];
		cout << "strData allocated : " << (void*)strData << endl;
	}
	void release() {
		delete[] strData;
		if (strData) cout << "strData released : " << (void*)strData << endl;
	}
	char *strData;
	int len;
};


String getName() {
	cout << "===== 2 =====" << endl;
	String res("Doodle");
	cout << "===== 3 =====" << endl;
	return res;
}
int main() {
	String a;
	cout << "===== 1 =====" << endl;
	a = getName();
	cout << "===== 4 =====" << endl;
}