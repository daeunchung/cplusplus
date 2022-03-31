// DP[N]의 경우 "N-2번 계단 까지의 최댓값 + N번계단" or "N-3번 계단까지의 최댓값 + N-1번계단 + N번계단"
#include <iostream>
#include <algorithm>
using namespace std;
int a[301];
int dp[301];
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[0] = 0;  
	dp[1] = a[1];	
	dp[2] = a[1] + a[2];  
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]) ;
	}	
	cout << dp[n] << '\n';
	return 0;
}