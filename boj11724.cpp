/*
11724 연결 요소의 수 (그래프 중에 덩어리의 수)
인접행렬 dfs : O(V^2)
인접리스트 dfs : O(V+E) = O(E)   정점의 차수들 순회하는거가 E 라서
트리를 제외한 대부분의 그래프는 V<=E 이기때문에 O(E) 라고 표현가능

bfs 는 '큐에 넣을때' 방문했음을 의미

BFS, DFS 두 방법 모두로 해결 가능
https://jdselectron.tistory.com/49 참고
*/
#include <iostream>
using namespace std;

int N, M, a, b, cnt;
// 한 정점과 연결된 모든 정점을 살펴보기 위한 "인접행렬"
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