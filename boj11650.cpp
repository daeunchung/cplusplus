#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int> > v;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	int n, a, b;
	cin >> n;
	for (; n--;) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i<v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}