#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) 
		return a.first < b.first;
	else 
		return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int n, a, b;
	cin >> n;
	vector<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}