// 영역 구하기 BFS DFS
// 오른쪽으로 90도 회전하면 배열의 [0][0] 가 시작하는 위치에서 (x,y) 좌표 (0,0) 으로 처리해줄 수 있음
// Input 이 0 2 4 4 이면 배열 [0][2] ~ [3][3] 색칠해주면 된다
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool land[101][101];	// visited OR square : 1, not visited OR territory : 0
int R, C, N, sr, sc, er, ec;
vector<int> v;

int bfs(int x, int y)
{
	int area = 0;
	queue<pair<int, int> > q;
	q.push({ x,y });
	land[x][y] = true;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		area++;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C || land[nx][ny]) continue;

			q.push({ nx,ny });
			land[nx][ny] = true;	
		}
	}
	return area;
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> C >> R >> N;	// R C 순이 아닌 C R 로 
	for (int i = 0; i < N; i++) {
		cin >> sr >> sc >> er >> ec;
		for (int a = sr; a < er; a++) {			// startrow ~ endrow-1
			for (int b = sc; b < ec; b++) {		// startcol ~ endcol-1
				land[a][b] = true;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!land[i][j]) {
				v.push_back(bfs(i, j));
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it << ' ';

	return 0;
}