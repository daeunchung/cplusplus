/*
���� �Ҵ� : int a;
���� �Ҵ� : ���α׷� ���� '���߿�' ����ڰ� ���ϴ´�� ������ �޸𸮿� �Ҵ��ϴ� �� 

*/
#include <iostream>
using namespace std;

// 65
int main(){
//	int n = 5;		int n(5);
	int n = int(5);
	int *a = new int(5); 
	// do something
	delete a;
	
	int *arr;	
	int len;
 	cin >> len;
 	arr = new int[len];
	// do something
	delete[] arr;	// �迭�� ���������� ���鼭 �޸� ���� 
}

// 66 
int main(){
	int *a = new int(5);
	int *b = new int(3);
	
	a = b;		// ���� ���� (������ ����) 
	*a = *b;	// ���� ���� (���� ����) ����Ű���ִ� ���� ���� ���� ���� 
	
	delete a;	
	delete b;	// ���� ����ÿ� ���� �߻� : a���� �̹� �����µ� ���� �޸𸮸� �� ���� ? => ���� 
	
//	Vector2 s1 = Vector2();
//	Vector2 s2(3, 2);
//	Vector2 s2 = Vector2(3, 2);
//	
//	Vector2 s2 = s1;	// copy constructor ���� Ÿ���� ��ü�κ��� ���ο� ��ü�� ���� 
//	Vector2 s3;
//	s3 = s1;			// assignment operator 
} 
