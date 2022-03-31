 //2178 미로탐색   거리구해야해서 BFS (한칸마다 이동거리 모두 저장한다고생각하는게 편함)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct pos{
	int x,y;
	pos(int x, int y) : x(x), y(y) {}
};
int dx[4] = {0,-1,1,0};
int dy[4] = {-1,0,0,1};
int m[101][101];
int N, M;
string str;

void bfs(int x, int y)
{
	queue<pos> q;
	q.push(pos(x, y));

	while (!q.empty()) {
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
			if (m[nx][ny] == 0) continue;
			if (m[nx][ny] == 1) {
				m[nx][ny] = m[cur_x][cur_y] + 1;
				q.push(pos(nx, ny));
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
			m[i][j] = str[j-1] - '0';
		}
	}

	bfs(1, 1);
	cout << m[N][M] << '\n';
	return 0;
}