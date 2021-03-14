/*
 다익스트라 알고리즘: 모든 간선의 가중치가 양수일 경우 (그리디 & 다이나믹프로그래밍) 
 가중치방향그래프 -> 벡터사용해서 인접리스트 
 dist[i] : 1->i 로 가는 최소비용 저장하는 1차원 배열(코드에서는최소힙 사용) 
 dist[]에서 최솟값을 찾는 과정을 정점의 갯수 n번만큼 반복해야한다. 
 => 우선순위큐를 사용하여 nlogn의 최소힙(최솟값찾는시간:logn) 구현 
 기존 경로보다 최소비용경로 찾았을 경우 relax 작업: 새로운 최솟값 갱신 
*/
// 다익스트라
#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int vex;	int dis;	// (정점, 거리)
	Edge(int a, int b){
		vex=a;	dis=b;
	}
	bool operator<(const Edge &b)const{
		return dis>b.dis;
		// 앞이 뒤보다 큰 내림차순 -> Priority queue에서 greater -> Min heap
		// dis최솟값이 항상 top으로  
	}
};
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	priority_queue<Edge> Q;	// Min heap
	vector<pair<int, int> > graph[30];	//인접리스트 vector사용한 가중치방향그래프
	int i, n, m, a, b, c;
	cin>>n>>m; 
	vector<int> dist(n+1, 2147000000);	// 1~n index필요, 전부무한대로 초기화
	for(i=1; i<=m; i++){
		cin>>a>>b>>c;
		graph[a].push_back(make_pair(b, c));
	} 
	Q.push(Edge(1, 0));
	dist[1]=0;
	// 다익스트라 //
	while(!Q.empty()){
		int now=Q.top().vex;
		int cost=Q.top().dis;
		Q.pop();
		if(cost>dist[now]) continue; // 찾기어려운코드
		for(i=0; i<graph[now].size(); i++){
			int next=graph[now][i].first;
			int nextDis=cost+graph[now][i].second;
			if(dist[next]>nextDis){
			// 새로운최솟값으로 갱신(릴렉스)되는 정점만 Push 
				dist[next]=nextDis;
				Q.push(Edge(next, nextDis));
			}
		}
	} 
	
	for(i=2; i<=n; i++){
		if(dist[i]!=2147000000) cout<<i<<" : "<<dist[i]<<endl;
		else cout<<i<<" : impossible"<<endl;
	}
	return 0;
}
