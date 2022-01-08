#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1050;
int n, m;
vector<int> v[MAX];
bool check_bfs[MAX];

void BFS()
{
	queue<int> q;
	q.push(0);	// initial starting point
	check_bfs[0] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < v[x].size(); i++)
		{
			// check all the neighboring vertices if they are visited or not
			int y = v[x][i];
			if (!check_bfs[y]) {
				check_bfs[y] = true;
				q.push(y);
			}

		}

	}
}
int main()
{
	scanf("%d %d", &n, &m);

	// graph presented by adjacency list(?)
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	BFS();
	return 0;
}