/* 가장 긴 바이토닉 부분 수열
* 가장 긴 증가부분수열(D)과 가장 긴 감소부분수열(D2) 를 구한 다음
* D[i] = i에서 끝나는 가장 긴 증가부분수열, D2[i] = i에서 시작하는 가장 긴 감소부분수열
* D[i] + D2[i] - 1 이 가장 큰 값을 찾으면 된다.
*/
#include <iostream>
using namespace std;
int a[1001];
int d[1001];
int d2[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}
	for (int i = n; i >= 1; i--) {
		d2[i] = 1;
		for (int j = i+1; j <= n; j++) {
			if (a[j] < a[i] && d2[i] < d2[j] + 1)
				d2[i] = d2[j] + 1;
		}
	}
	int max = -1;
	for (int i = 1; i <= n; i++) {
		if (max < d[i] + d2[i] - 1)
			max = d[i] + d2[i] - 1;
	}
	cout << max << '\n';
	return 0;
}