/* 1208. [S/W 문제해결 기본] 1일차 - Flatten D3 */
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int arr[100];
int dump, N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int Tnum = 1; Tnum <= 10; Tnum++)
	{
		cin >> dump;
		for (int i = 0; i < 100; i++)
			cin >> arr[i];
		
		sort(arr, arr + 100);	// 오름차순
		for (int i = 0; i < dump; i++)
		{
			arr[99]--;
			arr[0]++;
			sort(arr, arr + 100);
		}
		cout << "#" << Tnum << " " << arr[99] - arr[0] << "\n";
	}
	return 0;
}