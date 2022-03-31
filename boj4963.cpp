// ���� ����
// x,y �� ��ǥ�� �ƴ� ��ķ� ����
#include <iostream>
#include <queue>
using namespace std;
int a[51][51];						// �������
int d[51][51];
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };	// 8���� Ž��
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
			// �̵��� ���� ĭ�� map �����ȿ� ��� ��O, �湮X �̸� => ť �ְ� �湮O��
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