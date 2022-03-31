// 연결 요소의 갯수, 각 연결 요소의 크기 구하는 문제 -bfs, dfs
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int a[26][26];	// 지도
int danji[26][26];	// 방문여부 (0은 방문X), 단지번호
// danji[x][y] : 좌표의미X, 행렬을 의미 x행y열 : 따라서 [y][x] 로 해줄필요 X
int ans[25 * 25];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };	// N E S W
int n;

void bfs(int x, int y, int cnt)	// cnt 는 단지번호
{
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	danji[x][y] = cnt;	// 큐에 넣고 바로 방문 처리
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (a[nx][ny] == 1 && danji[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					danji[nx][ny] = cnt;
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			a[i][j] = str[j]-'0';
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && danji[i][j] == 0) {
				bfs(i, j, ++cnt);
				// bfs() 한번 할때마다 danji[i][j] 가 0->cnt 로 바뀌는 칸이 아주 많기 때문에
				// cnt 가 기하급수적으로 증가하지 않는다
			}
		}
	}
	cout << cnt << '\n';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[danji[i][j]] += 1;
		}
	}
	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}