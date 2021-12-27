/* BFS, DFS 두 방법 모두로 해결 가능
https://jdselectron.tistory.com/49 참고 */
#include <iostream>
using namespace std;

int N, M, a, b, cnt;
bool arr[1001][1001];
bool visited[1001];

void dfs(int node)
{
	visited[node] = true;
	for (int i = 1; i <= N; i++) {
		if (arr[node][i] && !visited[i]) {
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			++cnt;
			dfs(i);
		}
	}
	cout << cnt << '\n';
	return 0;
}