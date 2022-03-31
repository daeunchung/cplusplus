// ���� ����� ����, �� ���� ����� ũ�� ���ϴ� ���� -bfs, dfs
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int a[26][26];	// ����
int danji[26][26];	// �湮���� (0�� �湮X), ������ȣ
// danji[x][y] : ��ǥ�ǹ�X, ����� �ǹ� x��y�� : ���� [y][x] �� �����ʿ� X
int ans[25 * 25];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };	// N E S W
int n;

void bfs(int x, int y, int cnt)	// cnt �� ������ȣ
{
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));
	danji[x][y] = cnt;	// ť�� �ְ� �ٷ� �湮 ó��
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
				// bfs() �ѹ� �Ҷ����� danji[i][j] �� 0->cnt �� �ٲ�� ĭ�� ���� ���� ������
				// cnt �� ���ϱ޼������� �������� �ʴ´�
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