/* ���
��� ������ 1. ������ ã�� ���, 2. �Ұ����� ���, 3. ������͸� ȣ��(������ �ΰ���case�� �б�)
*/
#include <iostream>
using namespace std;
int t[21], p[21];
int n, ans = 0;

void func(int day, int sum)	// day ���� �Ǿ���. day�Ͽ� �ִ� ����� ���� ���� �����ؾ� �Ѵ�. ���ݱ��� ���� ������ sum
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