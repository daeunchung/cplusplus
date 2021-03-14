#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int k, n, ans = 1;
	cin >> n >> k;
	for (int i = n; i > n - k; i--) ans *= i;
	for (int i = k; i > 0; i--) ans /= i;
	cout << ans << '\n';
	return 0;
}