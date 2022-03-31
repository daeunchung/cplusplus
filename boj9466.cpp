/* 텀 프로젝트 DFS          학생의 수 (2 ≤ n ≤ 100,000)

모든 학생에 대해 dfs를 했으며 사이클이 완성된 학생은 dfs를 하지 않았다.
O(N ^ 2)의 시간 복잡도로 아무리 최적화해도 82퍼에서 시간 초과

문제 해결에 필요한 풀이 : 
만약 1번 학생을 dfs했을 때, 3번 학생과 5번 학생을 방문했다면, 
3번 학생과 5번 학생은 dfs를 하지 않는 풀이
모든 학생에 대해 한 번씩만 방문하므로 O(N)의 시간 복잡도
*/

#include <bits/stdc++.h>
using namespace std;

int T, n, scnt;
int with[100001];		// i -- choose---> with[i]
bool visited[100001];
bool inTeam[100001];
int cnt;

//void dfs(int i)	// 시간 초과 함수
//{
//	visited[i] = true;
//
//	if (with[i] == i) {
//		inTeam[i] = true;
//		return;
//	}
//	else if (!visited[with[i]] && inTeam[with[i]]) {
//		return;
//	}
//	else if (!visited[with[i]] && !inTeam[with[i]]) {
//		visited[with[i]] = true;
//		return dfs(with[i]);
//	}
//	else if (visited[with[i]] && !inTeam[with[i]]) {
//		for (int k = 1; k <= n; k++) {
//			if (visited[k])
//				inTeam[k] = true;
//		}
//	}
//}

void dfs(int i)
{
	visited[i] = true;
	if (!visited[with[i]]) {
		dfs(with[i]);
	}
	else
	{
		if (!inTeam[with[i]]) {
			// 역순으로 cycle 의 시작 우두머리를 찾을 때 까지 거슬러 올라가는 것
			for (int k = with[i]; k != i; k = with[k]) {
				cnt++;
			}
			cnt++;
		}
	}
	inTeam[i] = true;
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> T;
	while (T--) {
		memset(inTeam, 0, sizeof(inTeam));
		memset(visited, 0, sizeof(visited));

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> with[i];
		}
		//for (int i = 1; i <= n; i++) {
		//	if (!inTeam[i]) {
		//		memset(visited, 0, sizeof(visited));		// 나의 시간초과 코드 때 넣어준 부분
		//		dfs(i);
		//	}
		//}
		//int cnt = 0;
		//for (int i = 1; i <= n; i++) {
		//	if (!inTeam[i]) cnt++;
		//}
		//cout << cnt << '\n';

		cnt = 0;
		for (int i = 1; i <= n; i++) {
			// 아직 방문하지 않은 경우
			if (!visited[i]) {
				dfs(i);
			}
		}
		cout << n - cnt << "\n";
	}
	return 0;
}