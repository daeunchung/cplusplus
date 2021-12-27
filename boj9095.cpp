/* Á¡È­½Ä f(x) = f(x-1) + f(x-2) + f(x-3) */
#include <iostream>
using namespace std;

int N;
int arr[11];	// N < 11
int main() {

	int T;
	cin >> T;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i <= 10; i++) arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << arr[N] << '\n';
	}
	return 0;
}
