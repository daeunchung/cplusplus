// Ai와 Ai의 오큰수 사이에는 Ai 보다 작은 숫자만 올 수 있다
// 21-12-28
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	stack<int> s;
	s.push(0);
	for (int i = 1; i < n; i++)
	{
		if (s.empty()) {
			s.push(i);
		}
		while (!s.empty() && a[s.top()] < a[i]) {
			ans[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		ans[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}