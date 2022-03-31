// N�� 50���� �۰ų� ���� �ڿ����̰�, A�� B�� �� ���Ҵ� 100���� �۰ų� ���� ���� �ƴ� ����
#include <iostream>
#include <algorithm>
using namespace std;
int a[51], b[51];

bool desc(int a, int b) {
	return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 1; i <= n; i++) 
		cin >> b[i];
	sort(a + 1, a + n + 1, desc);
	sort(b + 1, b + n + 1);
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += a[i] * b[i];
	}

	cout << ans << '\n';
	return 0;
}