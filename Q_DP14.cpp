/* 14. �������� (�׷��� ����) 
 ����� ������ ������ '����' ��� �Ѵ�. ��忡 ������ ������ '��������'��� �Ѵ�.
 �� �۾�(���)�� ���������� ������ �����ϴ� degree[]�迭�� ����
 �� �Ŀ� �ڷᱸ�� Queue�� Ȱ���Ѵ�. degree[i]==0 �̸� queue�� �ش��۾��� �ִ´�.
 Q.top()�ϰ� Q.pop()�ϰ� pop�� ��尡 �����ϴ� �۾��� degree[]�迭���� �������ش�. (-1)
 degree[i]==0 (����Ǿ���� �۾��� ���ٴ� ��)�� �Ǵ� ���� �� ����� �̸� �� �ݺ� .
 
 ���� ��������� ä��X 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, m, a, b, score;
	cin>>n>>m;
	vector<vector<int> > graph(n+1, vector<int>(n+1, 0));
	vector<int> degree(n+1);
	queue<int> Q;
	for(int i=0; i<m; i++){
		cin>>a>>b;
		graph[a][b]=1;
		degree[b]++; // �������� ��� 
	}
	for(int i=1; i<=n; i++){
		if(degree[i]==0) Q.push(i);
	}
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		cout<<now<<" ";
		for(int i=1; i<=n; i++){
			if(graph[now][i]==1){
				degree[i]--;
				if(degree[i]==0) Q.push(i);
			}
		}
	}
	return 0;
}
