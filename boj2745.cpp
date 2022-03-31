// 진법 변환  (2 ≤ B ≤ 36)  B진법 수 N을 10진법으로 바꾸면, 항상 10억보다 작거나 같다.
#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	string str;		int B, expo;
	cin >> str >> B;
	ll ans = 0;
	for(int i = str.size()-1; i>=0; i--) {
		char ch = str[str.size() - 1 - i];

		if ('0' <= ch && ch <= '9') expo = ch - '0';
		else expo = ch - 'A' + 10;

		ans += expo * pow(B, i);
	}
	cout << ans << '\n';
	return 0;
}