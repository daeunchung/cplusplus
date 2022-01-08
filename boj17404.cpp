//#include <iostream>
//#include <algorithm>
//using namespace std;
//int dp[1001][3];
//int cost[1001][3];
//long long mod = 1000000000LL;
//
////  dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + cost[i][R]
////  No identical colors with the adjacent house
//int main()
//{
//	int n;	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
//	}
//	for (int i = 1; i < n; i++)
//	{
//		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
//		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
//		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
//	}
//	dp[n][0] = min( min(dp[n - 1][1], dp[n - 1][2]) + cost[1][1], min(dp[n - 1][1], dp[n - 1][2]) + cost[1][2]);
//	dp[n][1] = min( min(dp[n - 1][0], dp[n - 1][2]) + cost[1][0], min(dp[n - 1][0], dp[n - 1][2]) + cost[1][2]);
//	dp[n][2] = min( min(dp[n - 1][0], dp[n - 1][1]) + cost[1][0], min(dp[n - 1][0], dp[n - 1][1]) + cost[1][1]);
//	cout << min({ dp[n][0], dp[n][1], dp[n][2] }) << '\n';
//	// min 항이 3개 이상일때 {} 
//	return 0;
//}
