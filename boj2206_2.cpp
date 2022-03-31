// BFS - �� �μ��� �̵��ϱ� 
// ���� �� ������ �ѹ��� �������� �Ź� bfs ������°ǰ�? ����?
// ���� Ž������ ��� ���� �� ���� �հ� bfs�� �ϴ� ����� �ð� �ʰ�
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct pos {
	int x, y, z;	// z=1: ���ձ�1ȸ����, z=0: ���ձ�0ȸ����
	pos(int x, int y, int z) : x(x), y(y), z(z) {}
};
int dx[4] = { 0,-1,1,0 };	int dy[4] = { -1,0,0,1 };
int mapp[1001][1001];		// 1:��
int visited[1001][1001][2];	// 0���� �ʱ�ȭ
int N, M, ans;

int bfs(int x, int y, int z)
{
	queue<pos> q;
	q.push(pos(x, y, z));
	visited[x][y][z] = 1;

	while (!q.empty()) {
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		int cur_z = q.front().z;
		q.pop();

		if (cur_x == N && cur_y == M) {
			return visited[cur_x][cur_y][cur_z];
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			// ���� ������
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				// �̵��� ĭ�� ���̰�, ���� �ȶվ��� ��, �հ� ����
				if (mapp[nx][ny] == 1 && cur_z == 1) {
					visited[nx][ny][0] = visited[cur_x][cur_y][1] + 1;
					q.push(pos(nx, ny, 0));
				}
				// �̵��� ĭ�� ���� �ƴϰ�, �湮�������� ����
				if (mapp[nx][ny] == 0 && visited[nx][ny][cur_z] == 0) {
					visited[nx][ny][cur_z] = visited[cur_x][cur_y][cur_z] + 1;
					q.push(pos(nx, ny, cur_z));
				}
			}
		}
	}
	// ������ ���� X, Ž�� ����
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> N >> M;
	// Input
	for (int i = 1; i <= N; i++) {
		string str;	 cin >> str;
		for (int j = 1; j <= M; j++) {
			if (str[j - 1] == '1')
				mapp[i][j] = 1;
			else
				mapp[i][j] = 0;
		}
	}
	
	cout << bfs(1, 1, 1) << '\n';
	return 0;
}