/* pseudo code
�ִ� ȸ�Ǽ��� ���ؾ��ϱ� ������ ���۽ð��� �������� ������ �ȵǰ� ����ð��� �������� ��ƾ� �Ѵ�.
����ð����� �������� ������ �� ��, ���� ����ð��� ���ٸ� ���۽ð� �������� �������� ������ ���ش�
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