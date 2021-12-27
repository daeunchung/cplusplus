/*
void pointer : �ּҰ��� ����, ����ȵ������� �뷮�� Ÿ���� ����X . 
			���� ������ ���� ������ �� ���� . ������ ��ü���Ŀ� ���� �������̾�� �Ѵ� 
			
char *strData�� ����ϴ� �������� cout << strData ; �ϸ� �����Ϸ��� 
strData�� ���ڿ����� char*���������� �˼�����. ���� ���ڿ��� �ν�. strData�� NULL�̸� �����߻�
cout << (void*)strData ; �� ���� �ۼ��Ͽ� �����Ͱ��� ���

char *ptr = strData;
*ptr = 'A';
void *ptr = strData;
*ptr = 'A';				// ERROR : ���� ������ ��ü ���Ŀ� ���� �����Ϳ��� �մϴ�. 
*/

#include <iostream>		// <string.h>�� ���� 
#include <string.h>
using namespace std;

class String {
public:
	// �⺻������ 
	String(){
		cout << "String() ������ ȣ��" << endl;
		strData = NULL;									// 0�� macro�� NULL 
		len = 0;
	} 
	
	// ������ �����ε� 
	String(const char *str){
		cout << "String(const char*) ������ ȣ��" << endl;
//		strData = str;									// ��������� �ȵȴ� �޸��Ҵ� �������
		len = strlen(str);
		strData = new char[len+1];
		cout << "strData �Ҵ� : " << (void*)strData << endl;
//		char* strcpy(char *_Dest, const char *_Source){}
		strcpy(strData, str); 							// �������� 
	}
	
	// ��������� 
	String(const String &rhs){
		cout << "String(String &rhs) ������ ȣ��" << endl;
//		strData = rhs.strData;							// �����Ͷ� �����߻� 
		strData = new char[rhs.len+1]; 					// �޸� ���� �Ҵ� 
		cout << "strData �Ҵ� : " << (void*)strData << endl;
//		char* strcpy(char *_Dest, const char *_Source){}
		strcpy(strData, rhs.strData); 					// �������� 
		len = rhs.len;									// ������X int�� �������� 
	}
	
	// �Ҹ��� 
	~String(){
		cout << "~String() �Ҹ��� ȣ��" << endl;
		delete[] strData;
		cout << "strData ������ : " << (void*)strData << endl;
		strData = NULL;									// ���� 
	}
	
	// ���Կ����� �����ε� 
	String &operator=(const String &rhs){ // String operator=(const String rhs) �Է¹ް� ��ȯ������ ���� �Ͼ�� ��ü���� ���縦 �����ϱ� ���� ���������� �ް� ��ȯ 
		if(this != &rhs){	// �ڱ��ڽſ��� �����ϴ� ��츦 �����ϱ� ���Ͽ� 
			// ���λ����ϴ°� �ƴϰ� ������ �ִ� �޸𸮿� �����ϴ� �Ŷ� �޸� FLUSH �ʿ�
			delete[] strData; 								// strData�� NULL�̸� ���ʿ� delete[]�� �ƹ�����X 
			cout << "strData �޸𸮻���" << endl;
			strData = new char[rhs.len+1]; 					// �޸� ���� �Ҵ� 
			cout << "strData �Ҵ� : " << (void*)strData << endl;
			strcpy(strData, rhs.strData); 					// �������� 
			len = rhs.len;	
		} 
		return *this;
		// this : �Լ��� ����ɶ� �Լ��� �����ִ� ��ü�� �ּҰ�.
		// *this : ��ü �� ��ü 
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
	String s1("�ȳ�");
	String s2(s1);		// ��������� ȣ��� ��ü ���� 
//	String s2 = s1;		// ���� ������ ǥ�� (c++������) 
	
	String s3;			// ��ü ������. �⺻������ 
//	s3 = s1;			// ���Կ����� assignment operator �����ε� (=�����ڵ� ��ȯ���� ������ ��<-�� �� �־��ִ°�) 
	s3.operator=(s1);	// ���� ������ ǥ�� (s3 = s1 ǥ������ = s1�� ����޼���� ����)
	
	s3.operator=(s3);	// �̷��� ����Ǹ� �޸𸮻����ϰ� ���޸� �ļ� �� �����Ⱚ�� �����Ⱚ���� �����ϸ� ERROR 
						// �̸� ������ �� �־���Ѵ�. ���� �߰��ؾ��� 
	
	cout << s1.GetStrData() << endl;
	cout << s2.GetStrData() << endl;
	cout << s3.GetStrData() << endl;
} 


