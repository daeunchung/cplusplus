// 0 ���� BFS �ؼ� ġ� ���� 0���� ���������µ� �ɸ��� �ð�
// (0,0) ���� Ž���ϸ� �ڵ����� ġ�� ���ο� �ִ� ���ۿ��� ������ �� ���� ������
// ġ�� -  BFS
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char m[101][101];
bool visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int R, C, Hours, result;

bool bfs()
{
	int cnt = 0;
	queue<pair<int, int>> q;
	visited[0][0] = true;
	q.push({ 0,0 });
	Hours++;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C || visited[nx][ny]) continue;

			//  ������ ĭ�� 0�̸� ��� Ž��
			if (m[nx][ny] == '0') {
				q.push({ nx,ny });
			}
			// ������ ĭ�� ġ��� ġ� 0���� �ٲ��ְ� �ش� time �� Ž���� ġ���� ���� ī����
			else {
				m[nx][ny] = '0';
				cnt++;
			}
			visited[nx][ny] = true;
		}
	}

	//ġ� ���ٸ� �ð���, ���� bfs���� ���� ġ���� ������ ����� �� false��ȯ
	if (cnt == 0) {
		return true;
	}
	//ġ� �ִٸ� ���(ġ���� ����) ����
	else {
		result = cnt;
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) 
			cin >> m[i][j];

	while (true)
	{
		if (bfs()) break;
		memset(visited, false, sizeof(visited));
	}
	cout << --Hours << '\n' << result;

	return 0;
}
