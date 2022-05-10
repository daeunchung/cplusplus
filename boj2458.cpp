// input : vertex 수, edge 수 

#include <bits/stdc++.h>
using namespace std;
int graph[501][501];	// 초기화 false
#define INF 2147000000;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int v, e, a, b;
	cin >> v >> e;
	// vector< vector<bool> > graph(v, vector<bool>(v, 0));

	// fill in graph
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			graph[i][j] = INF;
		}
	}
	for (int i = 1; i <= e; i++) {
		cin >> a >> b;
		graph[a][b] = 0;
	}

	// floyd-warshall (from all nodes to all nodes)
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (graph[i][k] == 0 && graph[k][j] == 0) // && (i!=j) 가 없어도되는이유: i<j이면서 i>j 일수없어서 
					graph[i][j] = 0;
			}
		}
	}

	int answer = 0;

	for (int i = 1; i <= v; i++) {
		int count = 0;
		for (int j = 1; j <= v; j++) {
			if (graph[i][j] == 0 || graph[j][i] == 0) count++;
		}
		if (count == v - 1) {
			answer++;
		}
	}
	
	cout << answer << '\n';
	return 0;
}