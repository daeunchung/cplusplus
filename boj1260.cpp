#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001
int n, m, start;
int arr[MAX][MAX];
int visit[MAX];	// dfs 시 0->1, bfs 시 1->0 으로 사용

void dfs(int start) {
	cout << start << ' ';
	visit[start] = 1;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 1 || arr[start][i] == 0) continue;
		dfs(i);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = 0;

	while (!q.empty()) {
		start = q.front();
		cout << start << ' ';
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[start][i] == 0 || visit[i] == 0) continue;
			q.push(i);
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> n >> m >> start;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1;
	}
	dfs(start);
	cout << '\n';
	bfs(start);
	return 0;
}