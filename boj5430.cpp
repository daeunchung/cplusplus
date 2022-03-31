#include <iostream>
#include <string>
#include <deque>
#include <bits/stdc++.h>
using namespace std;
int T, n;
string cmd, str;
char ch;
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	cin >> T;
	while (T--)
	{
		bool ff = true;		// forward face
		bool check = true;	// error check
		cin >> cmd >> n;	
		deque<int> d(n);
		cin >> ch;
		for (int i = 0; i < n; i++) {
			cin >> d[i] >> ch;
		}
		if (n == 0) cin >> ch;

		for (int i = 0; i < cmd.length(); i++)
		{
			if (cmd[i] == 'R') {
				ff = !ff;
			}
			else if (cmd[i] == 'D') {
				if (d.empty()) {
					check = false;
					break;
				}
				if (ff) d.pop_front();
				else d.pop_back();
			}
		}

		// print
		if (!check) {
			cout << "error" << '\n';
			continue;
		}

		cout << '[';
		if (ff) {
			while(!d.empty()) {
				cout << d.front();
				d.pop_front();
				if (d.size() != 0) cout << ',';
			}
		}
		else {
			while (!d.empty()) {
				cout << d.back();
				d.pop_back();
				if (d.size() != 0) cout << ',';
			}
		}
		cout << ']' << '\n';
	}
	return 0;
}