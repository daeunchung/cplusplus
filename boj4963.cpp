// 섬의 개수
// x,y 를 좌표가 아닌 행렬로 간주
#include <iostream>
#include <queue>
using namespace std;
int a[51][51];						// 인접행렬
int d[51][51];
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };	// 8방향 탐색
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
int c, r;

void bfs(int x, int y, int cnt)
{
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	d[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			// 이동할 다음 칸이 map 범위안에 들고 땅O, 방문X 이면 => 큐 넣고 방문O로
			if (0 <= nx && nx < r && 0 <= ny && ny < c) {
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	while (true)
	{
		cin >> c >> r;
		if (r == 0 && c == 0) break;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> a[i][j];
				d[i][j] = 0;
			}
		}

		int cnt = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (a[i][j] == 1 && d[i][j] == 0) {
					bfs(i, j, ++cnt);
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}