// 0 에서 BFS 해서 치즈를 전부 0으로 만들어버리는데 걸리는 시간
// (0,0) 부터 탐색하면 자동으로 치즈 내부에 있는 구멍에는 접근할 수 없는 구조임
// 치즈 -  BFS
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

			//  인접한 칸이 0이면 계속 탐색
			if (m[nx][ny] == '0') {
				q.push({ nx,ny });
			}
			// 인접한 칸이 치즈면 치즈를 0으로 바꿔주고 해당 time 에 탐색한 치즈의 수를 카운팅
			else {
				m[nx][ny] = '0';
				cnt++;
			}
			visited[nx][ny] = true;
		}
	}

	//치즈가 없다면 시간과, 이전 bfs에서 나온 치즈의 개수를 출력한 후 false반환
	if (cnt == 0) {
		return true;
	}
	//치즈가 있다면 결과(치즈의 개수) 갱신
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
