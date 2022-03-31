/*
ABCDE
 사람 : 정점			친구관계 : 간선
 인접행렬, 인접리스트, 간선리스트 모두 활용해서 풀이 연습

 A-B : 간선리스트에 들어있는 모든 간선을 조회하면 A-B 인 간선 찾을 수 있음
 C-D : 간선리스트에 들어있는 모든 간선을 조회하면 C-D 인 간선 찾을 수 있음
 B-C : 인접행렬의 정점사용. 임의의 두 정점이 연결되어있는지 유무를 가장 빠르게 찾을 수 있음
 D-E : 인접리스트로 한 정점과 연결되어있는 모든 정점, 한 정점과 연결된 간선을 찾는 방법

=> 그래프의 각 저장형태가 어떠한 연산에 용이한지를 잘 알고 있어야 언제 뭘 쓸지 안다.


코드에서 간선리스트를 생성, 저장하는 부분은 X
이유 : 모든 간선이 필요한 상황 O, 임의의 한 정점과 연결된 간선을 저장하는 것은 인접리스트에서 해줄 것이기 때문
a[][]인접행렬, g[]인접리스트, vector<pair<int, int> >edges간선리스트

문제에서 친구관계는 쌍방(양방향) 이라서 3가지 그래프 표현 자료구조에 (from,to) 와 (to,from) 모두 푸쉬백
그래프 간선의 수 = 친구관계 * 2


*/
#include <vector>
#include <iostream>
using namespace std;
bool a[2000][2000];				// 인접행렬
vector<int> g[2000];			// 인접리스트
vector<pair<int, int> > edges;	// 간선리스트
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		edges.push_back({ from, to });
		edges.push_back({ to, from });
		a[from][to] = a[to][from] = true;
		g[from].push_back(to);
		g[to].push_back(from);
	}

	// A는 B와 친구다. - 간선리스트 전부 순회
	// B는 C와 친구다. - 인접행렬 : 임의의 두 정점의 연결유무를 O(1)에 
	// C는 D와 친구다. - 간선리스트 전부 순회
	// D는 E와 친구다. - 인접리스트 : 한 정점에 연결된 모든 간선 찾기
	m *= 2;
	for (int i = 0; i < m; i++)
	{
		int A = edges[i].first;
		int B = edges[i].second;
		for(int j = 0; j < m; j++)
		{
			int C = edges[j].first;
			int D = edges[j].second;
			// A, B, C, D 는 전부 다른 정점이다
			if (A == B || A == C || A == D || B == C || B == D || C == D)
			{
				continue;	// 이번(i,j) 는 조건 불만족 -> 다음 (i,j) 로 
			}
			if (!a[B][C]) continue;
			for (int E : g[D]) {
				// E 는 A, B, C, D 와 같은 정점이면 안된다
				if (A == E || B == E || C == E || D == E)
				{
					continue;
				}
				cout << 1 << '\n';	// 친구관계 만족
				return 0;
			}
		}
	}
	cout << 0 << '\n';	// 친구관계 불만족
	return 0;
}