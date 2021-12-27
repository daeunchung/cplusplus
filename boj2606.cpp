/* DFS, BFS 둘 다로 풀 수 있음 */
#include <iostream>
using namespace std;
bool arr[101][101];
bool visited[101];
int n, edge, cnt, a, b;

int DFS(int node)
{
	if(node != 1) cnt++;
	visited[node] = 1;
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && arr[node][i]) {
			 DFS(i);
		}
	}
	return cnt;
}

int main() {
	cin >> n >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}
	cout << DFS(1) << '\n';
}