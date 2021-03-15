/*
정적 할당 : int a;
동적 할당 : 프로그램 실행 '도중에' 사용자가 원하는대로 변수를 메모리에 할당하는 것 

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
	delete[] arr;	// 배열을 순차적으로 돌면서 메모리 해제 
}

// 66 
int main(){
	int *a = new int(5);
	int *b = new int(3);
	
	a = b;		// 얕은 복사 (참조만 복사) 
	*a = *b;	// 깊은 복사 (값을 복사) 가리키고있는 공간 속의 값을 복사 
	
	delete a;	
	delete b;	// 얕은 복사시에 문제 발생 : a에서 이미 지웠는데 없는 메모리를 또 지워 ? => 에러 
	
//	Vector2 s1 = Vector2();
//	Vector2 s2(3, 2);
//	Vector2 s2 = Vector2(3, 2);
//	
//	Vector2 s2 = s1;	// copy constructor 같은 타입의 객체로부터 새로운 객체를 생성 
//	Vector2 s3;
//	s3 = s1;			// assignment operator 
} 
