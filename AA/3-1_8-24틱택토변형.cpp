#include <iostream>
#include <string>
#include <ctime> 
#include <Windows.h>
using namespace std;
int main() {
	srand(unsigned(time(NULL)));
	int test[3][3] = { 
		{1,0,1},
		{0,1,1},
		{0,0,1}
	};
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (test[i][0] == 1 && test[i][1] == 1 && test[i][2] == 1)
			cnt++;
		if (test[0][i] == 1 && test[1][i] == 1 && test[2][i] == 1)
			cnt++;
	}
	if(test[0][2] == 1 && test[1][1] == 1 && test[2][0] == 1) cnt++;
	if(test[0][0] == 1 && test[1][1] == 1 && test[2][2] == 1) cnt++;
	cout << cnt;
}
