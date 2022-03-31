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
				// ��, ��, �������ʴ밢�� 3���� �ϳ��� 0�̸� d[i][j]�� �׳� 1 (���簢���� �߰��� �������� �ҿ�X)
				// dp[i][j] �� 1�� ���� ���� ��������� ���簢���� �������� ���簢������ �Ƿ��� 
				// dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] 3���� ��� + ��(���簢�������ϴܲ�����)
				// => �׸��Ͽ� 3������ �ּҰ��� �߿��� ��
				dp[i][j] += min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
				if (ans < dp[i][j]) ans = dp[i][j];
			}
		}
	}
	cout << ans * ans << '\n';
	return 0;
}