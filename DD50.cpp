#include <iostream>
using namespace std;
int main(){
//	int arr[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
//	for(int i=0; i<10; i++){
//		cout << arr[i] << endl;
//	}


// ������� for�� Range-base for statement
// �迭�� �� ĭ�� �����ΰ�ó�� ���
//	int arr[10] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
//	for(int n : arr){
//		// arr���� ��� n�� ����, n�� arr[i]�� �Ǵ°� 
//		cout << arr[i] << endl;
//		n++; // for�������� int n; �ѰͰ� �����ؼ� ���� arr[i]�� �����Ű�� �ʴ´�. 
//	} 
//	for(int &n : arr){
//		cout << arr[i] << endl;
//		n++; // int &n reference ������ ���Ѵ�. 
//	} 


//	int a(5);	//int a=5;
//	int &p = a;
//	p=10;
//	cout<<p<<endl;	cout<<a<<endl;


	 
// C++11���� ����� �����Ҽ����°� r-value,  �����Ҽ��ִ°� l-value 
	int a(5);
	// �����Ҽ��ִº���a, �����Ҽ����»��3, �Լ���a*a 
	int &r1 = a;
//	int &&r1 = a;		// ���� : rvalue������ lvalue�� ���ε��� �� �����ϴ�. 
//	int &r2 = 3; (����)	// 3�� ���� �޸𸮻� ����X , ���� r2�� 3�� ����ų������. 
	int &&r2 = 3;	// &r2 reference���� ��� &&r2 r-value ��� 
	int &&r3 = a * a;
	return 0;
} 
