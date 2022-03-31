// 게임 이분탐색
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MAXX 1000000000	// 십억
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long X, Y;
	cin >> X >> Y;
	int Z = Y * 100 / X;
	if (Z >= 99) {
		cout << -1 << '\n';
		return 0;
	}

	int lb = 0, ub = MAXX, m;
	while (lb +1 <ub)
	{
		m = lb + (ub - lb) / 2;
		if ((Y + m) * 100 / (X + m) > Z) ub = m;
		else lb = m;
	}
	cout << ub << '\n';
	return 0;
}