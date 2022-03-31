 //진법 변환 2
 //(2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
string ans;

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	ll N, B;	cin >> N >> B;
	while (N > 0) {
		int i = N % B;
		if (i < 10) ans += (char)(i + 48);
		else {
			ans += (char)(i + 55);
		}
		N /= B;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << '\n';
	return 0;
}