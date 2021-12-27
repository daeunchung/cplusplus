/* dp */
// DP[a] = b 의 의미는 "a번째 값이 가지는 가장 긴 증가하는 부분수열의 길이는 b입니다."

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001];
int dp[1001];

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(dp[i], ans);
	}
	cout << ans << "\n";

	return 0;
}