// 골드바흐 파티션
// 골드바흐의 추측 : 2보다ㅏ 큰 짝수는 두 소수의 합으로 나타낼 수 있다.
// 테스트 케이스의 개수 T (1 ≤ T ≤ 100),  정수 N은 짝수이고, 2 < N ≤ 1,000,000
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N;
int arr[1000000 +1];	// true(소수가 아니다), 남아있으면 false(소수)
void Eratosthenes()
{
	// arr[x]==0 : 소수 아니다
	arr[0] = arr[1] = 0;
	for (int i = 2; i <= 1000000; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(1000000); i++)
	{
		if (arr[i] == 0) continue;
		for (int j = i * i; j <= 1000000; j += i) {
			arr[j] = 0;
		}
	}
}

int main()
{
	int T;
	ios_base::sync_with_stdio(false);	cin.tie(0);	cout.tie(0);
	Eratosthenes();
	cin >> T;
	while (T--)
	{
		cin >> N;
		int cnt = 0;
		for (int i = 2; i <= N/2; i++) {
			if (arr[i] * arr[N-i] != 0) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}