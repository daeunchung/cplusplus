String some_function(String str)	// str1�� �Ű������� �Ѿ���� ���������� ȣ�� 
{
	String strReturn;
	// do something
	return strReturn;				// strReturn�� str2�� �Ѿ�ö� ���������� ȣ�� 
}

int main(){
	String str1 = "Test String";	// (const char*) constructor ����
	String str2 = str1;				// copy constructor "=" �� ������X ������ȣ��O. str1���� str2 ��ü�� ����
	// C++�����Ϸ��� �� ������ String str2(str1); �� �����ϰ� �ؼ�

	String str3;					// default constructor
	str3 = str1;					// assignment operator "=" �� equal������(����)�� ���� 
	
	str2 = some_function(str1);		// call by value 	str1�� some_function�Լ��� �Է°����� ���鼭 ���������� ȣ�� 
}
/*
 ���������� (Copy Initializer Constructor) 
 : ���� Ÿ���� ��ü�κ��� ���ο� ��ü�� ���� X::X(const X&) 
 ���������ڰ� ���Ǵ� ��� 1. �ٸ���ü�κ��� ��������� 2. ��ü�� �Լ��� ���ڷ� �ѱ涧 3. �Լ����� ��ü�� �����Ҷ� 
 */
