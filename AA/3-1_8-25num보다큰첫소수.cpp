#include <iostream>
#include <string>
#include <ctime> 
#include <Windows.h>
using namespace std;
int main(){
	srand(unsigned(time(NULL))); 
	int num = 50000000;
	int result = 0;
	//문제1) num 보다 큰 첫번째 소수를 result 에 저장하는함수 
	bool run = true;
	while(run){
		int count = 0;
		for(int i = 1; i <= num; i++){
			if(num % i == 0) count += 1;
			if(count > 2) break;	// num을 키우면 process time이 단축됨을 체감할 수 있다. 
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

