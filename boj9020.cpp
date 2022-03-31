// 골드바흐의 추측 : 2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int T, n;

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	// 체
	int arr[10001];
	for (int i = 1; i <= 10000; i++) arr[i] = i;
	for (int i = 2; i <= 10000; i++)
	{
		if (arr[i] != 0) {
			for (int j = i * i; j <= 10000; j += i)
				arr[j] = 0;
		}

	}
	
	cin >> T;
	while (T--)
	{
		int a = 0, b = 0;
		cin >> n;
		int diff = 10000;
		for (int i = 2; i <= n - 2; i++) {
			if (arr[i] * arr[n - i] != 0) {
				if (diff > arr[n - i] - arr[i] && arr[n - i] - arr[i] >= 0) {
					diff = arr[n - i] - arr[i];
					a = arr[i];	b = arr[n - i];
				}
			}
		}
		cout << a << ' ' << b << '\n';
	}
	return 0;
}