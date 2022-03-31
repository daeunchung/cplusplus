#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++) {
			dp[i][j] = str[j - 1] - '0';
			if (dp[i][j] == 1)
			{
				// 상, 좌, 왼쪽윗쪽대각선 3개중 하나라도 0이면 d[i][j]는 그냥 1 (정사각형이 중간에 끊어지면 소용X)
				// dp[i][j] 의 1로 인해 새로 만들어지는 정사각형이 세어지는 정사각형으로 되려면 
				// dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] 3개의 경우 + 나(정사각형우측하단꼭짓점)
				// => 그리하여 3원소의 최소값이 중요한 것
				dp[i][j] += min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
				if (ans < dp[i][j]) ans = dp[i][j];
			}
		}
	}
	cout << ans * ans << '\n';
	return 0;
}