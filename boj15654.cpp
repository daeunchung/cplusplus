#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 9
using namespace std;

int n, m, num;
int arr[MAX] = { 0, };
vector<pair<int, bool> > visited;
pair<int, bool> p;

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!visited[i].second)
		{
			visited[i].second = true;
			arr[cnt] = visited[i].first;
			dfs(cnt + 1);
			visited[i].second = false;
		}
	}
}

bool comp(pair<int, bool>& p1, pair<int, bool>& p2)
{
	return p1.first < p2.first;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num;
		p = make_pair(num, false);
		visited.emplace_back(p);
	}
	sort(visited.begin(), visited.end(), comp);
	dfs(0);
}