#include <iostream>
#include <string>
#include <ctime> 
#include <Windows.h>
using namespace std;
int main(){
	srand(unsigned(time(NULL))); 
	int num = 50000000;
	int result = 0;
	//����1) num ���� ū ù��° �Ҽ��� result �� �����ϴ��Լ� 
	bool run = true;
	while(run){
		int count = 0;
		for(int i = 1; i <= num; i++){
			if(num % i == 0) count += 1;
			if(count > 2) break;	// num�� Ű��� process time�� ������� ü���� �� �ִ�. 
		}
		if(count == 2){
			run = false;
			result = num;
			break;
		}
		num += 1;
	}
	cout << result << endl;
}

