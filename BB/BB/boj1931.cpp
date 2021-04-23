/* pseudo code
최대 회의수를 구해야하기 때문에 시작시간을 기준으로 잡으면 안되고 종료시간을 기준으로 잡아야 한다.
종료시간으로 오름차순 정렬을 한 후, 만약 종료시간이 같다면 시작시간 기준으로 오름차순 정렬을 해준다
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int> > v;
int n;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	if (p1.second == p2.second)
		return p1.first < p2.first;
	else
		return p1.second < p2.second;
}

int main() {
	ios::sync_with_stdio(false);	cin.tie(NULL);
	cin >> n;
	int st, end;
	for (int i = 0; i < n; i++) {
		cin >> st >> end;
		v.emplace_back(make_pair(st, end));
	}

	sort(v.begin(), v.end(), compare);

	int current = v[0].second;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (current <= v[i].first) {
			cnt++;
			current = v[i].second;
		}
	}
	cout << cnt << '\n';
	return 0;
}