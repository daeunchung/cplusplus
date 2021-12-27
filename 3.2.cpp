/*
 String class : c++ string�� �������� String class�� ����
 ������ : ����Ʈ������(�迭������), ����������
 ������ : �Ҵ��� ���ҽ� ������, ����/���ϰ� X
  		  ����� ���Ǵ� Ŭ������ ��� �����ڴ� virtual�̾����.
		  base class �����ͷ� ���Ե� derived class�� ��� virtual�� �ƴϸ� base class �ش�κ��� destructor�� ȣ��ȴ�.
		   
 ��°� ������ : BaseŬ������ �����ڸ� ȣ���ϴ� ���
  - DerivedClass(Args) : BaseClass(Args) {body}  // �θ�Ŭ���������� ���� �߰��� �� �־��� �κ��� {body}�� �ۼ�
   
 ���������� (Copy Initializer Constructor) 
 : ���� Ÿ���� ��ü�κ��� ���ο� ��ü�� ���� X::X(const X&) 
 ���������ڰ� ���Ǵ� ��� 1. �ٸ���ü�κ��� ��������� 2. ��ü�� �Լ��� ���ڷ� �ѱ涧 3. �Լ����� ��ü�� �����Ҷ� 
 
 shallow copy vs deep copy
 Operator Overloading ������ �ߺ�����, �������� �켱������ ���ռ���
 String Ŭ������ �����ϴ� �Լ���� ���� 
 
 Storage Class : ���η� 
  c++���� �������� �����Ǵ� ��ġ�� ũ�� 3���� �ִ�. �������� ��ġ�� ���� ������ �����Ⱓ
  life time�� ������ 
 - �ڵ����� (Automatic Variables) : ���ǽ� ����, ���� ������ ����. STACK : reentrant�����԰���
 - �������� (Static Variables) : ���α׷� ���۽� ����, ���α׷� ������ ����. DATA SEGMENT ���� �Ҵ�
 - �������� (Dynamic Variables) : new, delete, HEAP�� 
 
���� ! local variable�� global variable�� life time���� �ٸ� �̾߱�.
local�� ���ǵ� ���ȿ����� ,  ��𿡼��� ���� ������ global 
������ ���ǵǴ� ��ġ, �����Ǵ¹��(static, new).. �� ���� Storage Class�� ��������. 
*/


// Storage Class �� ��
#include <stdio.h>
int global;									// static
void main(){
	static int staticvar = 10;				// main�ۿ��� ���ٸ��ϴ� static 
	
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
