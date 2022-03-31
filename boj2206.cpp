// BFS - 벽 부수고 이동하기 - 못풀었음
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct pos {
	int x, y;
	pos(int x, int y) : x(x), y(y) {}
};
int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };
int mapp[1001][1001];
int N, M;
string str;
int removeWall = 0;

void bfs(int x, int y)
{
	queue<pos> q;
	q.push(pos(x, y));

	while (!q.empty()) {
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		q.pop();

		int check = 0;
		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > M || mapp[nx][ny] == 1) {
				check++;
				continue;
			}
			if (mapp[nx][ny] == 0) {
				mapp[nx][ny] = mapp[cur_x][cur_y] + 1;
				q.push(pos(nx, ny));
			}
		}
		if (check == 4) {
			if (removeWall == 0) {
				removeWall++;
				check = 0;
			}
			else {
				mapp[N][M] = -1;
				return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++) {
			mapp[i][j] = str[j - 1] - '0';
		}
	}

	bfs(1, 1);
	cout << mapp[N][M] << '\n';
	return 0;
}