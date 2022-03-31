// ��� ���� ĥ�ϴ� ����� �ּڰ�
#include <iostream>
#include <algorithm>
using namespace std;
#define R 0
#define G 1
#define B 2

int dp[1001][3];
int cost[1001][3];
long long mod = 1000000000LL;

//  dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + cost[i][R]
//  No identical colors with the adjacent house
int main()
{
	int n;	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i][R] >> cost[i][G] >> cost[i][B];
	}

	int ans = 1000 * 1000 + 1;	// �ִ����� ä�����´�
	for (int k = 0; k <= 2; k++) { // house1's color �� �����ؼ� �Ʒ����� houseN == house1 �϶��� ����
		for (int j = 0; j <= 2; j++) {
			if (j == k)
				dp[1][j] = cost[1][j];
			else
				dp[1][j] = 1000 * 1000 + 1;
		}
		for (int i = 2; i <= n; i++)
		{
			dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + cost[i][R];
			dp[i][G] = min(dp[i - 1][R], dp[i - 1][B]) + cost[i][G];
			dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + cost[i][B];
		}
		for (int j = 0; j <= 2; j++)
		{
			// 1�� ���� ���� 2��, N�� ���� ���� ���� �ʾƾ� �Ѵ�.
			if (j == k) continue;
			ans = min(ans, dp[n][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}
