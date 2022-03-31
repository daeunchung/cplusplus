#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// DP[a][b] = c :: a�� ���ؼ� �� ���� b�� �Ǵ� ����� ���� c��
// DP[K][N] = DP[K-1][0] + DP[K-1][1] + ... + DP[K-1][N]
long long d[201][201];
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int N, K;	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
			}
			d[i][j] %= 1000000000;
		}
	}
	cout << d[K][N] << '\n';
	return 0;
}