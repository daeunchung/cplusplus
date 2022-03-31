#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T, n, m, x;
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> T;
	while (T--)
	{
		int count = 0;
		cin >> n >> m;
		queue<pair<int, int>> q;
		priority_queue<int> pq; 
		for (int i = 0; i < n; i++) {
			cin >> x;
			q.push(make_pair(i, x));
			pq.push(x);
		}
		while (!q.empty()) {
			int idx = q.front().first;
			int ipt = q.front().second;
			q.pop();
			if (pq.top() == ipt) {
				pq.pop();
				count++;
				if (idx == m) {
					cout << count << '\n';
					break;
				}
			}
			else q.push(make_pair(idx,ipt));
		}
	}
	return 0;
}