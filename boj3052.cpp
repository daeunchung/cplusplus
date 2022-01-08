#include <iostream>
#include <string>
using namespace std;
int r[42];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 10;
	while (T--) {
		int n;
		cin >> n;
		r[n % 42]++;
	}
	int cnt = 0;
	for (int i = 0; i < 42; i++) {
		if (r[i] != 0) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}
