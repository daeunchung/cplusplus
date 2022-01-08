/*
15990 : 같은 수를 두 번 이상 연속해서 사용하면 안 된다.
4 = 121 13 31

15988 :
4 = 1111 112 121 211 13 31
D[i] = D[i-3] + D[i-2] + D[i-1]
*/
#include <iostream>
using namespace std;
const long long mod = 1000000009LL;
long long d[1000001];

int main()
{
	d[1] = 1;	d[2] = 2;	d[3] = 4;
	for (int i = 4; i < 1000001; i++) d[i] = (d[i - 3] + d[i - 2] + d[i - 1]) % mod;
	int T;	cin >> T;
	while (T--) {
		int n; cin >> n;
		cout << d[n] << '\n';
	}
	return 0;
}