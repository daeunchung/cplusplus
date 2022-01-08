#include <iostream>
#include <algorithm>
using namespace std;
int t[501][501];
int d[501][501];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= i; j++) 
			cin >> t[i][j];

	//d[1][1] = t[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)
				d[i][j] = d[i - 1][1] + t[i][j];
			else if (j == i)
				d[i][j] = d[i - 1][j - 1] + t[i][j];
			else
				d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + t[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < d[n][i]) ans = d[n][i];
	}
	cout << ans << '\n';
	return 0;
}