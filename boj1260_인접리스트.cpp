// http://codeplus.codes/8749c68651d64a4993d3e47c476886e4
// ���� url�� ġ�� �Ʒ��� ���� (���� ����Ʈ �ҽ�)
// ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), Ž���� ������ ������ ��ȣ V
// https://www.acmicpc.net/source/share/8749c68651d64a4993d3e47c476886e4
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
int n, m, start, x, y;
int arr[MAX][MAX];		// ���� ���
vector<int> a[MAX];		// ���� ����Ʈ
bool visited[MAX];			// dfs �� 0->1, bfs �� 1->0 ���� ���

// adjacency matrix �������, adjacency list ��������Ʈ
void dfsAM(int start) {
	cout << start << ' ';
	visited[start] = 1;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 1 || arr[start][i] == 0) continue;
		dfsAM(i);
	}
}

void bfsAM(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 0;

	while (!q.empty()) {
		start = q.front();
		cout << start << ' ';
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[start][i] == 0 || visited[i] == 0) continue;
			q.push(i);
			visited[i] = 0;
		}
	}
}

void dfsAL(int node)
{
	visited[node] = true;
	cout << node << ' ';
	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i];
		if (visited[next] == false) {
			dfsAL(next);
		}
	}
}

void bfsAL(int node)
{
	queue <int> q;
	memset(visited, false, sizeof(visited));
	visited[node] = true;
	q.push(node);
	while (!q.empty())
	{
		int node = q.front();
		cout << node << ' ';
		q.pop();
		for (int i = 0; i < a[node].size(); i++)
		{
			int next = a[node][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> n >> m >> start;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;

		// ���� ���
		//arr[x][y] = arr[y][x] = 1;
		// ���� ����Ʈ
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	//dfsAM(start);
	//cout << '\n';
	//bfsAM(start);
	//cout << '\n';

	dfsAL(start);
	cout << '\n';
	bfsAL(start);
	cout << '\n';
	return 0;
}