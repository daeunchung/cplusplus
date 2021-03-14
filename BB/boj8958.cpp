#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, ans;
	cin >> n;
	string b;
	for (int i = 1; i <= n; i++) {
		ans = 0;
		int cnt = 0;
		cin >> b;
		for (int j = b.size(); j >= 0; j--) {
			if (b[j] == 79) cnt++;
			else cnt = 0;
			ans += cnt;
		}
		cout << ans << endl;
	}
	return 0;
}