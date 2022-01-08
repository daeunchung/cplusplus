/* 
Á¡È­½Ä : D[i] = D[i-2]*2 + D[i-1]
*/
#include <iostream>
using namespace std;
int arr[1001];
int N;

int main() {
	cin >> N;
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2]*2;
		arr[i] %= 10007;
	}
	cout << arr[N] << '\n';
	return 0;
}