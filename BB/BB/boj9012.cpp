#include <iostream>
#include <string>
#include <stack>
using namespace std;

int flag;
stack<int> st;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		flag = 1;
		while (!st.empty()) st.pop();

		string p;
		cin >> p;
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == '(') st.push(1);
			else if (p[j] == ')') {
				if (!st.empty())
					st.pop();
				else {
					flag = -1;
					break;
				}
			}
		}
		if (!st.empty()) flag = -1;
		
		if (flag == 1) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}