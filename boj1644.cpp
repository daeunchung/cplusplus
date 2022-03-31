// 에리스토테네스의 체   1 ≤ N ≤ 4,000,000
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check[4000001];    // false 로 초기화
vector<int> prime;

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	int N;
	cin >> N;

    for (int i = 2; i * i <= N; i++) {
        if (!check[i]) {
            for (int j = i + i; j <= N; j += i)
                check[j] = true;
        }
    }
    for (int i = 2; i < N + 1; i++) {
        if (!check[i])
            prime.push_back(i);
    }

    int ans = 0, sum = 0, lo = 0, hi = 0;
    while (1) {
        if (sum >= N) {
            sum -= prime[lo++];
        }
        else if (hi == prime.size()) {
            break;
        }
        else {
            sum += prime[hi++];
        }
        if (sum == N) ans++;
    }
    cout << ans << '\n';
	return 0;
}