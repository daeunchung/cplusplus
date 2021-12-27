/*
68�������� ���������� ������������ ��������� �ٲ��ֱ�
69�������� �������縦 ������������ ��������� �ٲ��ֱ� 
	- �̵��ø�ƽ(?) �������� �������ִ� C++11 ���ο����� 
	���ʿ��� ��������(�޸𸮻��� & �������� ������)�� �ݺ��Ǹ� ��ȿ����.
	�ϳ��� �޸𸮸� �����Ͱ� ����Ű�� ���� �ٸ� �����Ͱ� ����Ű�� ���� �Ǵٸ� �����Ͱ� ����Ű��... => �̵��ȴٰ� ǥ��
	<�̵� �ø�ƽ> ���� �̵�������, �̵����Կ����� ����ϸ� �������� ���� 
	
	�̵� �ø�ƽ�� ���ؼ��� rvalue�� �ʿ��ϴ�. 
	
	r-value ��ȣ�� �캯���� ���� �ִ� ���̴ٶ�� �濡�� �Ļ��� �ܾ� . �º��� ���� 
	l-value �� ��ȣ�� �º��� �� �� �ְ� �캯���� �� �� �ִ�. 
	int a = 5;
	a = 5;
	a = a;
	5 = a; (X) 
	C++ ���� ��� ���� rvalue �Ǵ� lvalue �ε� �캯�����ü�������rvalue,  �º��캯�ٿü�������lvalue 
	
	int f() { return 5; }
	�޸𸮿� ����� ������ �Ǿ��ִ� ��쿡 �װ��� ������ �����ϴ�.
	f() = 1; (X)  
	f()�� ��ȯ�ϴ� return�� ��ü�� �ӽð�ü�� �´�.  �ӽð�ü�� �޸𸮻� ������ ������ �Ǿ��ִ�.
	�ٵ� �� �ӽð�ü�� 1�� ������ �� ���°�? 
	=> f()�� rvalue�̱� ���� ���ʿ� �º��� �ü����� �޸𸮻� ������ �Ǿ������� rvalue�� f()=1; ���� ���̾ȵ� 
	
	lvalue �޸𸮻� ����O
	�ӽð�ü�� ���������� �Լ��� ��ȯ�ϱ⿡ �޸𸮻� ������ �Ǿ������� ��ȯ���� ������ �� ���⶧���� rvalue�̴� 
	
*** ��� : �ӽð�ü�� rvalue�̴� ***
	
	String &&r = getName();	// &&r r-value �����ڿ� getName()�� ��ȯ�ϴ� String�ӽð�ü�� �������� �� �ִ�(����X) 
	r-value ��ȯ���� �������̰� ǥ���ϱ� ���� r-value�����ڸ� �̿��ؼ� �������� �� �ִ�. 
	

*******************************************************************************************************
	
 return res;������ ȣ��� ��ÿ� res�� lvalue������ res�� ��ȯ�Ǵ� ���ȿ� res�� rvalue�� ���ֵȴ�. 
 res�� rvalue�� ���ֵǾ�� �̵������� String(String &&rhs){} �� ȣ���� �ȴ�. ... ���� ����� 
 ���� ���Լ��� ������ �ȵǾ��ٸ� String(const String &rhs)�� rvalue�� �޴´�.
 rvalue�� ������ �� ���� ���� �ǹ�
 
 String &rhs ����Ÿ�Կ� const�� �ٿ��� �ٲپ��ָ� �����Ұ��� �����̱⶧���� 
 rvalue�� �޴� �����Լ� String(String &&rhs)�� ���� ��쿡 String(const String &rhs)�� rvalue�� �޾��ش�. "����"
 �״�� �Ű����� Ÿ�Կ� const �Ⱥٿ��ָ� rvalue�� ���� ���Ѵ�.

 ���: String(String &&rhs){} �� ���� ��� String(const String &rhs){}�� rvalue�� �޾��� �� �ִ�.
 ������ const ����������. ����X�� �����ϱ� ����. const ������ String(String &rhs)�̸� rvalue ���޴´�. 

 res�� �ӽð�ü�� ���簡 �Ǵ� �������� res�� rvalue�� ���ְ� �ǰ� String(String &&rhs){}�� �޾����� �̵������� ����
 
 ��� : 
 lvalue �������� String(const String &rhs){} ���������, String &operator=(const String &rhs){} ������Կ�����
 rvalue �������� String(String &&rhs){} �̵�������, 	String &operator=(String &&rhs){} �̵����Կ����� C++11���� �߰��� �̵��ø�ƽ 
 (rvalue : �ӽð�ü, ����������ϴ� �Լ����� ��ȯ�Ǳ� ������ res���� ��ü) 
 
  
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
	// ��������� 
	String(const String &rhs){
		cout << "String(const String&) : " << this << endl;
		len = rhs.len;								
		alloc(len);
		strcpy(strData, rhs.strData); 				
	}
	
	// �̵������� 
	String(String &&rhs){
		// ��������� �Ҹ��ڰ� ������ �ѹ��� ȣ�� ! 
		cout << "String(String &&) : " << this << endl; 
		len = rhs.len;
		strData = rhs.strData;
		rhs.strData = NULL;		// �Ҹ���ȣ��Ǿ� delete[] strData;���൵ �޸𸮶� ������ ����� ������ ����X 
	}
	
	~String(){
		cout << "~String() : " << this << endl;
		release();
		strData = NULL;									
	}
	
	// ���� ���� ������ 
	String &operator=(const String &rhs){ 
		cout << "String &operator=(const String&) : " << this << endl;
		if(this != &rhs){	
			release(); 
			len = rhs.len;
			alloc(len);	
			strcpy(strData, rhs.strData); 	
		} 
		return *this;		// *this : ��ü����ü, this : ��ü�ּҰ� 
	}
	
	// �̵� ���� ������
	String &operator=(String &&rhs){
		cout << "String &operator=(String &&) : " << this << endl; 
		len = rhs.len;
		strData = rhs.strData;
		rhs.strData = NULL;
		return *this; // ���������� ����ϴ� String a = b = c; ���������� ��ü�� ��ȯ 
	}
	 
	char *GetStrData() const {
		return strData;
	}
	int GetLen() const {
		return len;
	}
	void SetStrData(const char *str){		// �̰ǿ��ִ°��� �� �𸣰���.. 
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






/* �ܼ� ���â
 
String() : 0x72fdf0
===== 1 =====
===== 2 =====
String(const char*) : 0x72fe00
strData allocated : 0xb36fe0
===== 3 =====
String(const String&) : ====================================================================
strData allocated : 			���� �� ( res-> �ӽð�ü )���������, �̵������� ȣ��κ��� 
~String() :	����res					����� �ȵ���.. -> �ذ�: �̰� DEVC++���� �ȵǴµ� VS���� ������µ�. ���־�Ʃ��� ��� ! 
strData released : ���ڿ��ּ� ==============================================================
String &operator=(const String&) : 0x72fdf0
strData allocated : 0xb37350
~String() : 0x72fe00
strData released : 0xb36fe0
===== 4 =====
~String() : 0x72fdf0
strData released : 0xb37350

--------------------------------
Process exited after 0.3519 seconds with return value 0
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/

