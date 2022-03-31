// 0. 이분탐색 vector pair : 이 코드 아님 못했음 아직

// 1. Iterator를 써보려 했으나 시간초과.. ^^
// 테스트는 결과 나옴. 그러나 boj는 시간 초과
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, a, b;

bool compare(const pair<int, int>&a, const pair<int, int>&b) {
	return a.first < b.first;
}

bool check(const pair<int, int>&a) {
	if (a.first == b) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;
	vector<pair<int, int> > v;
	vector<pair<int, int> >::iterator iter;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(make_pair(a, 1));
	}
	sort(v.begin(), v.end(), compare);

	for (iter = v.begin() + 1; iter != v.end(); iter++) {
		if ((iter - 1)->first == iter->first) {
			(iter - 1)->second++;
			iter = v.erase(iter);
		}
	}
	iter = v.end() - 1;
	if ((iter - 1)->first == iter->first) {
		(iter - 1)->second++;
		iter = v.erase(iter);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b; 
		iter = find_if(v.begin(), v.end(), check);
		if(iter != v.end())
			cout << iter->second << " ";
		else
			cout << "0 ";
	}
	return 0;
}
