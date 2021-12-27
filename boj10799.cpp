// 21-12-26
#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	string str;
	getline(cin, str);
	int n = str.size();
	stack<int> s;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (str[i] == '(') {
			s.push(i);
		}
		else {
			if (i == s.top() + 1) {	// 레이저
				s.pop();
				ans += s.size();
			}
			else {	// 쇠막대기의 끝부분
				s.pop();
				ans += 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}