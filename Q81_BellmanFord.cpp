/*
 ����-���� �˰��� : 1������ ���ؼ�, 2������ ���ؼ�, ... n-1������ ���ؼ� �̷��� ���Ȯ�� 
 ��������� ���鵹���� ����� �����ϴ� ���� ����Ŭ�� �����ؼ��� �ȵȴ�.
 ������ n���� ������ �ִ� n-1 , ���� n���� ������ ���ؼ� �� ��������ΰ� ������ ������ ���� ����Ŭ�� �����Ѵٴ� �̾߱� 
 
 ��) ������ k+1�� ���� ��� : ������ k������ ��� + ��� ������ ���� �ּڰ��� ���ŵǴ��� Ȯ��  	
*/
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int dist[101];
struct Edge{
	// ��簣���� Ȯ���ؾ��ϱ� ������ ����ü�� ��������
	int s, e, val;
	Edge(int a, int b, int c){
		s=a;	e=b;	val=c;
	}
}; 
int main(){
	freopen("input.txt", "rt", stdin);
	vector<Edge> Ed;	// ������������ 
	int i, n, m, a, b, c, j, s, e;
	scanf("%d %d", &n, &m);	// n������, m������ 
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));	
	}
	for(i=1; i<=n; i++){
		dist[i]=2147000000; // ���ǻ���Ŭ�� ������ ������ ��ӵ����ʱ⶧���� 1�����迭��ok
	}
	scanf("%d %d", &s, &e);
	dist[s]=0;
	for(i=1; i<n; i++){	// ������ i�� ���ļ� �����ϴ¹�� Ž�� (����1�� ~ ����n-1��)
		for(j=0; j<Ed.size(); j++){
			int u=Ed[j].s;
			int v=Ed[j].e;
			int w=Ed[j].val;
			if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;	// Relax(����) 
			}
		}
	}
	// ������ ������ n��°�� �ּҺ���ΰ� �ִ��� Ȯ�� -> ���ǻ���Ŭ�� �����ϴ��� Ȯ�� 
	for(j=0; j<Ed.size(); j++){
		int u=Ed[j].s;
		int v=Ed[j].e;
		int w=Ed[j].val;
		if(dist[u]!=2147000000 && dist[u]+w<dist[v]){ // �ּҺ���� ���Ž� ���ǻ���Ŭ���� 
			printf("-1\n");
			exit(0);
		}
	}
	printf("%d\n", dist[e]);
	return 0;
}
