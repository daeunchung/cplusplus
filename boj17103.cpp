// ������ ��Ƽ��
// �������� ���� : 2���٤� ū ¦���� �� �Ҽ��� ������ ��Ÿ�� �� �ִ�.
// �׽�Ʈ ���̽��� ���� T (1 �� T �� 100),  ���� N�� ¦���̰�, 2 < N �� 1,000,000
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N;
int arr[1000000 +1];	// true(�Ҽ��� �ƴϴ�), ���������� false(�Ҽ�)
void Eratosthenes()
{
	// arr[x]==0 : �Ҽ� �ƴϴ�
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