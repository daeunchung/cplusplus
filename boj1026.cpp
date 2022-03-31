// N은 50보다 작거나 같은 자연수이고, A와 B의 각 원소는 100보다 작거나 같은 음이 아닌 정수
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