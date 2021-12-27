#include <iostream>
#include <stack>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	stack<int> s;
	int n, k, ans = 0;
	cin >> n;
	for (; n--;) {
		cin >> k;
		if (k != 0) 
			s.push(k);
		else 
			s.pop();
	}
	for (int i = 0; !s.empty(); i++) {
		ans += s.top();
		s.pop();
	}
	cout << ans << '\n';
	return 0;
}