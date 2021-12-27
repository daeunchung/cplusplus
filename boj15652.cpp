/*  15650 조합문제에서 중복만 허용 */
#include <iostream>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };

void dfs(int idx, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = idx; i <= n; i++)
	{
		visited[i] = true;
		arr[cnt] = i;
		dfs(i, cnt + 1);	// {2,2,2}, {3,3,3} 가능토록
		visited[i] = false;
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
}