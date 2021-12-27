/* DFS 컴포넌트 갯수 구하는 문제 */
#include <iostream>
#include <cstring>	// for memset
using namespace std;
bool visited[51][51];
bool map[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int m, n, k;

void DFS(int y, int x) {
	if (visited[y][x]) return;

	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 <= ny && ny < n && 0 <= nx && nx < m)
			if (map[ny][nx]) 
				DFS(ny, nx);
	}
}



int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);		cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] && !visited[i][j])
				{
					DFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		memset(visited, false, sizeof(visited));
		memset(map, false, sizeof(map));
	}
	return 0;
}
