/*
 벨만-포드 알고리즘 : 1개간선 통해서, 2개간선 통해서, ... n-1개간선 통해서 이렇게 비용확인 
 벨만포드는 돌면돌수록 비용이 감소하는 음의 사이클이 존재해서는 안된다.
 정점이 n개면 간선은 최대 n-1 , 만약 n개의 간선을 통해서 더 적은비용경로가 나오면 무조건 음의 사이클이 존재한다는 이야기 
 
 예) 간선을 k+1개 도는 경우 : 간선을 k개도는 경우 + 모든 간선을 돌며 최솟값이 갱신되는지 확인  	
*/
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int dist[101];
struct Edge{
	// 모든간선을 확인해야하기 때문에 구조체를 간선으로
	int s, e, val;
	Edge(int a, int b, int c){
		s=a;	e=b;	val=c;
	}
}; 
int main(){
	freopen("input.txt", "rt", stdin);
	vector<Edge> Ed;	// 간선보관벡터 
	int i, n, m, a, b, c, j, s, e;
	scanf("%d %d", &n, &m);	// n정점수, m간선수 
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));	
	}
	for(i=1; i<=n; i++){
		dist[i]=2147000000; // 음의사이클이 없는한 갱신이 계속되지않기때문에 1차원배열도ok
	}
	scanf("%d %d", &s, &e);
	dist[s]=0;
	for(i=1; i<n; i++){	// 간선을 i개 거쳐서 도착하는방법 탐색 (간선1개 ~ 간선n-1개)
		for(j=0; j<Ed.size(); j++){
			int u=Ed[j].s;
			int v=Ed[j].e;
			int w=Ed[j].val;
			if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;	// Relax(갱신) 
			}
		}
	}
	// 간선의 갯수가 n개째에 최소비용경로가 있는지 확인 -> 음의사이클이 존재하는지 확인 
	for(j=0; j<Ed.size(); j++){
		int u=Ed[j].s;
		int v=Ed[j].e;
		int w=Ed[j].val;
		if(dist[u]!=2147000000 && dist[u]+w<dist[v]){ // 최소비용경로 갱신시 음의사이클존재 
			printf("-1\n");
			exit(0);
		}
	}
	printf("%d\n", dist[e]);
	return 0;
}
