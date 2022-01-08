/* DP 문제
arr[n] = 하나를 놓는 경우 arr[n-1] +  두개를 놓는 경우 arr[n-2]  */
#include <iostream>
using namespace std;
int arr[1001];
int N;
//int main() {
//	cin >> N;
//	arr[1] = 1;		arr[2] = 2;
//	for (int i = 3; i <= N; i++)
//		arr[i]= (arr[i - 1] + arr[i - 2]) % 10007;
//	cout << arr[N] << '\n';
//	return 0;
//}

int main() {
	cin >> N;
	arr[0] = 1;		
	arr[1] = 1;
	for (int i = 2; i <= N; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 10007;
	}
	cout << arr[N] << '\n';
	return 0;
}