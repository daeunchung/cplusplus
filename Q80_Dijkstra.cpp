/*
 ���ͽ�Ʈ�� �˰���: ��� ������ ����ġ�� ����� ��� (�׸��� & ���̳������α׷���) 
 ����ġ����׷��� -> ���ͻ���ؼ� ��������Ʈ 
 dist[i] : 1->i �� ���� �ּҺ�� �����ϴ� 1���� �迭(�ڵ忡�����ּ��� ���) 
 dist[]���� �ּڰ��� ã�� ������ ������ ���� n����ŭ �ݺ��ؾ��Ѵ�. 
 => �켱����ť�� ����Ͽ� nlogn�� �ּ���(�ּڰ�ã�½ð�:logn) ���� 
 ���� ��κ��� �ּҺ���� ã���� ��� relax �۾�: ���ο� �ּڰ� ���� 
*/
// ���ͽ�Ʈ��
#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int vex;	int dis;	// (����, �Ÿ�)
	Edge(int a, int b){
		vex=a;	dis=b;
	}
	bool operator<(const Edge &b)const{
		return dis>b.dis;
		// ���� �ں��� ū �������� -> Priority queue���� greater -> Min heap
		// dis�ּڰ��� �׻� top����  
	}
};
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	priority_queue<Edge> Q;	// Min heap
	vector<pair<int, int> > graph[30];	//��������Ʈ vector����� ����ġ����׷���
	int i, n, m, a, b, c;
	cin>>n>>m; 
	vector<int> dist(n+1, 2147000000);	// 1~n index�ʿ�, ���ι��Ѵ�� �ʱ�ȭ
	for(i=1; i<=m; i++){
		cin>>a>>b>>c;
		graph[a].push_back(make_pair(b, c));
	} 
	Q.push(Edge(1, 0));
	dist[1]=0;
	// ���ͽ�Ʈ�� //
	while(!Q.empty()){
		int now=Q.top().vex;
		int cost=Q.top().dis;
		Q.pop();
		if(cost>dist[now]) continue; // ã�������ڵ�
		for(i=0; i<graph[now].size(); i++){
			int next=graph[now][i].first;
			int nextDis=cost+graph[now][i].second;
			if(dist[next]>nextDis){
			// ���ο��ּڰ����� ����(������)�Ǵ� ������ Push 
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
