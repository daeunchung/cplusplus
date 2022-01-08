/* 수n개가 주어졌을때, 가능한 모든 쌍의 GCD의 합을 구하는 문제 */
#include <iostream>
using namespace std;
int gcd(int x, int y)
{
	if (y == 0) return x;
	else return gcd(y, x % y);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int arr[101] = { 0, };
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
		}
		long long sum = 0;
		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++)
				sum += gcd(arr[i], arr[j]);
		cout << sum << '\n';
	}
	return 0;
}