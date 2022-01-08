/* 가장 긴 증가하는 부분 수열 LIS Longest Increasing Subsequence 
* D[i] = i번째에서 끝나는 LIS의 길이 (수열시작 ~ A[j], A[i] 일때 수열의 길이)
* D[i] = max(D[j] + 1), j<i, A[j]<A[i] , D[1] = 1
* 
* 11055 는 가장 큰 증가하는 부분 수열 : 수분 수열의 합이 최대이어야 한다 
* D[i] = max(D[j] + A[i]), j<i, A[j]<A[i] , D[1] = A[1]
*/
#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int d[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) {
		d[i] = a[i];
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + a[i] )
				d[i] = d[j] + a[i];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < d[i]) ans = d[i];
	}
	cout << ans << '\n';
	return 0;
}