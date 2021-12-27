#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX];
int v[MAX];
bool visited[MAX];

void dfs(int idx, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = idx; i < n; i++)
	{
		visited[i] = true;
		arr[cnt] = v[i];
		dfs(i, cnt + 1);
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> v[i];
	sort(v, v + n);
	dfs(0, 0);

	return 0;
}