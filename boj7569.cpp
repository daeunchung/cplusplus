#include <iostream>
#include <queue>
using namespace std;

int M, N, H;
int T[100][100][100];
struct pos {
	int x, y, z;
	pos(int x, int y, int z) : x(x), y(y), z(z) {}
};

int dx[6] = { 0, 1, 0 , -1,0,0 };
int dy[6] = { 1, 0, -1, 0 ,0,0};
int dz[6] = { 0, 0, 0, 0 ,1,-1};

queue<pos> q;
void BFS()
{
	while (!q.empty()) {
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		int cur_z = q.front().z;

		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			int nz = cur_z + dz[i];

			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
			if (T[nx][ny][nz] == 0) {
				T[nx][ny][nz] = T[cur_x][cur_y][cur_z] + 1;
				q.push(pos(nx, ny, nz));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> M >> N >> H;
	// 입력값이 공백있게 따로 따로 주어짐 (그대로받아도 OK)
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> T[i][j][k];
				if (T[i][j][k] == 1) q.push(pos(i,j,k));	// 익은 토마토만 큐에 넣는다.
			}
		}
	}
	BFS();

	/* 날짜 계산 및 출력 */
	int cnt = 0;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				// 익지않은 토마토(0)가 존재할 경우
				if (T[i][j][k] == 0) {
					cout << -1 << '\n';
					return 0;
				}
				// 최댓값 찾기
				if (cnt < T[i][j][k]) {
					cnt = T[i][j][k];
				}
			}
		}
	}
	cout << cnt - 1 << '\n';
	return 0;
}