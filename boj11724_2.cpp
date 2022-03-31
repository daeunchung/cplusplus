/*
* With 인접리스트
*/
#include <iostream>
#include <vector>
using namespace std;

int N, M, a, b, cnt;
bool check[1001];
vector<int> arr[1001];	// 인접리스트

void dfs(int node)
{
	check[node] = true;
	for (int i = 0; i < arr[node].size(); i++) {
		int next = arr[node][i];
		if (!check[next]) {
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (!check[i]) {
			++cnt;
			dfs(i);
		}
	}
	cout << cnt << '\n';
	return 0;
}