// 크루스칼은 간선을 정렬하여 트리를 만들어 나가는 것이고, 
// 프림은 정점을 연결해 가면서 트리를 만들어 간다

// 그래프에서 최소비용트리를 만들어내는 Kruskal 알고리즘 Edge : s--val-->e
// 간선의 가중치값으로 오름차순 정렬, Cycle 회로가 결성되지 않게 간선을 선택 
// 회로가 결성되지 않는하에 간선을 n-1개 선택 
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int unf[10001];	// 메모이제이션을 위한 배열 
struct Edge{
	int s, e, val;
	Edge(int a, int b, int c){
		s=a; e=b; val=c;
	}
	bool operator<(const Edge &b)const{
		return val<b.val;	// 오름차순 
	}
};
int Find(int v){
	if(v==unf[v]) return v;
	else return unf[v]=Find(unf[v]);
}
void Union(int a, int b){
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}
int main(){
//	freopen("input.txt", "rt", stdin);
	vector<Edge> Ed;
	int i, n, m, a, b, c, cnt=0, res=0;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){ 
		// 모든 정점을 자기자신 단독의 집합으로 초기화 
		unf[i]=i;
	}
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));
	}
	// 가중치 값으로 오름차순 정렬 
	sort(Ed.begin(), Ed.end());
	for(i=0; i<m; i++){
		int fa=Find(Ed[i].s); 
		int fb=Find(Ed[i].e);
		if(fa!=fb){	// fa==fb인데 Union하면 순환회로가 되어버린다. 
			res+=Ed[i].val;
			Union(Ed[i].s, Ed[i].e);
		} 
	}
	printf("%d\n", res); 
	return 0;
} 
