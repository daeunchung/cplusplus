/* 퇴사
재귀 설계방법 1. 정답을 찾은 경우, 2. 불가능한 경우, 3. 다음재귀를 호출(보통은 두가지case로 분기)
*/
#include <iostream>
using namespace std;
int t[21], p[21];
int n, ans = 0;

void func(int day, int sum)	// day 일이 되었다. day일에 있는 상담을 할지 말지 결정해야 한다. 지금까지 얻은 수익은 sum
{
	if(day == n + 1) {
		if (ans < sum) ans = sum;
		return;
	}
	if (day > n + 1) {
		return;
	}
	func(day + 1, sum);
	func(day + t[day], sum + p[day]);
}
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> t[i] >> p[i];
	func(1, 0);
	cout << ans << '\n';
	return 0;
}