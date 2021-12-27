#include <iostream>
using namespace std;
int main(){
//	int arr[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
//	for(int i=0; i<10; i++){
//		cout << arr[i] << endl;
//	}


// 범위기반 for문 Range-base for statement
// 배열의 각 칸을 변수인것처럼 사용
//	int arr[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
//	for(int n : arr){
//		// arr안의 모든 n을 본다, n이 arr[i]가 되는것 
//		cout << arr[i] << endl;
//		n++; // for문내에서 int n; 한것과 동일해서 실제 arr[i]를 변경시키지 않는다. 
//	} 
//	for(int &n : arr){
//		cout << arr[i] << endl;
//		n++; // int &n reference 변수라서 변한다. 
//	} 


//	int a(5);	//int a=5;
//	int &p = a;
//	p=10;
//	cout<<p<<endl;	cout<<a<<endl;


	 
// C++11에서 적용된 수정할수없는값 r-value,  수정할수있는값 l-value 
	int a(5);
	// 수정할수있는변수a, 수정할수없는상수3, 함숫값a*a 
	int &r1 = a;
//	int &&r1 = a;		// 오류 : rvalue참조를 lvalue에 바인딩할 수 없습니다. 
//	int &r2 = 3; (에러)	// 3은 실제 메모리상 저장X , 따라서 r2는 3을 가리킬수없다. 
	int &&r2 = 3;	// &r2 reference변수 대신 &&r2 r-value 사용 
	int &&r3 = a * a;
	return 0;
} 
