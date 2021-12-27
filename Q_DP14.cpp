/* 14. 위상정렬 (그래프 정렬) 
 연결된 간선의 갯수를 '차수' 라고 한다. 노드에 들어오는 차수를 '진입차수'라고 한다.
 각 작업(노드)의 진입차수의 갯수를 저장하는 degree[]배열을 생성
 그 후에 자료구조 Queue를 활용한다. degree[i]==0 이면 queue에 해당작업을 넣는다.
 Q.top()하고 Q.pop()하고 pop한 노드가 수행하는 작업을 degree[]배열에서 삭제해준다. (-1)
 degree[i]==0 (선행되어야할 작업이 없다는 뜻)이 되는 것이 또 생기면 이를 또 반복 .
 
 답이 어려가지라서 채점X 
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
		degree[b]++; // 진입차수 계산 
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
