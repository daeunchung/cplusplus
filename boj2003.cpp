#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000
typedef long long ll;
int Data[MAXN + 1];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll  N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> Data[i];

	int left = 0, right = 0, cnt = 0;
	ll sum = 0;
	while (left <= right && right <= N)
	{
		if (sum > M)
		{
			sum -= Data[left++];
		}
		else if (sum == M) {
			cnt++;
			sum += Data[right++];
		}
		else if(sum < M)
		{
			sum += Data[right++];
		}
	}
	cout << cnt << '\n';
}