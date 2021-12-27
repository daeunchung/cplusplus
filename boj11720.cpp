#include <iostream>
#include <string>
using namespace std;
int main() {
	int n, ans = 0;
	char a;
	cin >> n;
	for (int i = 0; i<n; i++) {
		cin >> a;
		ans += (int)a - 48;
	}
	cout << ans;
	return 0;
}
