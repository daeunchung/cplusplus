#include <iostream>
#include <string>
#include <ctime> 
#include <Windows.h>
using namespace std;

int main(){
	srand(unsigned(time(NULL))); 
	int arr1[4] = {10, 30, 4, 2};
	int arr2[4] = {54, 4, 10, 3};
	int arr3[4] = {0,0,0,0};
	int cnt = 0;
	//����3) arr1 �� arr2 �� ���ؼ� ���� ���� ������ arr3�� �����ϴ��Լ� 
	// ��) ==> {10, 4 , 0 , 0}
	for(int i = 0; i<4; i++){
		for(int j = 0; j<4; j++){
			if(arr1[i] == arr2[j])
			arr3[cnt++] = arr1[i];
		}
	}
	for(int i = 0; i<4; i++)
		cout << arr3[i] << " ";
	return 0;
}

