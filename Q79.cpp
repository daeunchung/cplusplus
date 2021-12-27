// ���� : ������ �����Ͽ� (n��) Ʈ�� ���� Edge : --val-->e (e, val)
// ������ �ּҰ��� ���ϱ� ���� �켱����ť �ּ��� �ڷᱸ�� ���
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int ch[30];
struct Edge{
	int e;
	int val;
	Edge(int a, int b){
		e=a;
		val=b;
	}
	bool operator<(const Edge &b)const{
		return val>b.val;	// Q.push, Q.pop�Ҷ����� val�������� �ּ������� ���ĵȴ�. 
	}
};
int main(){
//	freopen("input.txt", "rt", stdin);
	priority_queue<Edge> Q;	// �����ڿ����ε����� �ּ������� �����س����� 
	vector<pair<int, int> > map[30];
	int i, n, m, a, b, c, res=0;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	} 
	Q.push(Edge(1, 0));
	while(!Q.empty()){
		Edge tmp=Q.top();
		Q.pop();
		int v=tmp.e;
		int cost=tmp.val;
		if(ch[v]==0){
			res+=cost;
			ch[v]=1;
			// v������ ����� ��� �������� push 
			for(i=0; i<map[v].size(); i++){
				if(ch[map[v][i].first]==0) Q.push(Edge(map[v][i].first, map[v][i].second));
			}
		}
	}
	printf("%d\n", res);	
	return 0;
}

