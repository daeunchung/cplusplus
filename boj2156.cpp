/*
D[i][0] i번째 줄에서 연속 0개의 포도주 마실때 최대양 ( 즉, i번째 포도주잔 마시지 않는다. )
D[i][j] i번째 줄에서 연속 j개의 포도주 마실때 최대양 ( j = 0,1,2 가능. 연속 3잔 불가능 )
*/
#include <iostream>
#include <algorithm>
using namespace std;
int p[10001];
int d[10001][3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];

	d[0][0] = d[0][1] = d[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		d[i][0] = max({ d[i - 1][0], d[i - 1][1], d[i - 1][2] });
		d[i][1] = d[i - 1][0] + p[i];
		d[i][2] = d[i - 1][1] + p[i];
	}
	cout << max({ d[n][0], d[n][1], d[n][2] }) << '\n';
	return 0;
}