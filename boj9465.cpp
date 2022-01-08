/*
D[i][0] i열에서 스티커를 뜯지 않을 경우 점수 최댓값
D[i][j] i열에서 j번째 스티커를 뜯은 경우 점수 최댓값
최백준 : D[i][j] = 2*i 에서 얻을 수 있는 최대점수, i번 열에서 뜯는 스티커는 j
*/
#include <iostream>
#include <algorithm>
using namespace std;
int p[100001][2];	// sticker points
int d[100001][3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> p[j][i];

		d[0][0] = d[0][1] = d[0][2] = 0;
		for (int i = 1; i <= n; i++) {
			d[i][0] = max({ d[i - 1][0], d[i - 1][1], d[i-1][2] });
			d[i][1] = max(d[i - 1][2], d[i - 1][0]) + p[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + p[i][1];
		}
		cout << max({ d[n][0], d[n][1], d[n][2] }) << '\n';
	}
	return 0;
}