/* 
D[i][j] = 길이가 i이고 마지막 숫자가 j인 오르막 수의 개수
D[1][j] = 1, D[i][j] += D[i-1][k] (0 <= k <= j)
*/ 

#include <iostream>
using namespace std;
long long d[1001][10];
long long mod = 10007;
int main()
{
	int n;
	cin >> n;
	for (int j = 0; j < 10; j++) d[1][j] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				d[i][j] += d[i - 1][k];
				d[i][j] %= mod;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; i++) ans += d[n][i];
	cout << ans % mod << '\n';
	return 0;
}