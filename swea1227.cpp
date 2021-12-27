/* 1227. [S/W 문제해결 기본] 7일차 - 미로2 D4 */
#include <iostream>
#include <queue>
using namespace std;
int testcase = 10, answer;
int map[100][100];
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

struct Pos {
	int x, y;
};
Pos startPos, endPos;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= testcase; i++)
	{
		// Input
		cin >> i;
		for (int i = 0; i < 100; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < 100; j++) {
				map[i][j] = str[j] - '0';
				if (map[i][j] == 2) startPos = { i, j };
				else if (map[i][j] == 3) endPos = { i, j };
			}
		}

		// 초기화
		answer = 0;
		bool visited[100][100] = { false };
		queue<Pos> q;

		// bfs
		q.push(startPos);
		visited[startPos.x][startPos.y] = true;
		while (!q.empty())
		{
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (nx < 0 || ny < 0 || nx >= 100 || ny >= 100) continue;	// 미로이탈시 탈락
				if (visited[nx][ny]) continue;	// 이미 방문했으면 탈락
				if (map[nx][ny] == 1) continue;	// 벽이면 탈락
				if (map[nx][ny] == 3) {
					answer = 1;
					break;
				}
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
			if (answer == 1) break;
		}
		cout << "#" << i << " " << answer << "\n";
	}
	return 0;
}