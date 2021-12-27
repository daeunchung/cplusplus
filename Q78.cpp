// ũ�罺Į�� ������ �����Ͽ� Ʈ���� ����� ������ ���̰�, 
// ������ ������ ������ ���鼭 Ʈ���� ����� ����

// �׷������� �ּҺ��Ʈ���� ������ Kruskal �˰��� Edge : s--val-->e
// ������ ����ġ������ �������� ����, Cycle ȸ�ΰ� �Ἲ���� �ʰ� ������ ���� 
// ȸ�ΰ� �Ἲ���� �ʴ��Ͽ� ������ n-1�� ���� 
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int unf[10001];	// �޸������̼��� ���� �迭 
struct Edge{
	int s, e, val;
	Edge(int a, int b, int c){
		s=a; e=b; val=c;
	}
	bool operator<(const Edge &b)const{
		return val<b.val;	// �������� 
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
		// ��� ������ �ڱ��ڽ� �ܵ��� �������� �ʱ�ȭ 
		unf[i]=i;
	}
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));
	}
	// ����ġ ������ �������� ���� 
	sort(Ed.begin(), Ed.end());
	for(i=0; i<m; i++){
		int fa=Find(Ed[i].s); 
		int fb=Find(Ed[i].e);
		if(fa!=fb){	// fa==fb�ε� Union�ϸ� ��ȯȸ�ΰ� �Ǿ������. 
			res+=Ed[i].val;
			Union(Ed[i].s, Ed[i].e);
		} 
	}
	printf("%d\n", res); 
	return 0;
} 
