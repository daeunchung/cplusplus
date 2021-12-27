/* 12. 플로이드-와샬 (그래프 최단거리) 
 다익스트라, 벨만포드 : 한정점에서 다른정점으로  
 플로이드-와샬 : 모든정점에서 모든정점으로 dy[][]2차원배열(Knapsack algorithm과 동일한 원리) 
 dis[][]가 dy[][]와 동일 
 dis[i][j] = i노드->j노드 로 가는 최소비용 
  k노드를 경유할 경우 i->k->j dis[i][k]+dis[k][j]    와 기존dis[i][j]값을 비교하여 min값으로 갱신(Relax) 
 k가 1 2 3 ... 이중for문 돌며 계속 갱신 (플로이드-와샬 은 경로출력도 가능) 
 
 예) k=3일때 i=5, j=4이면 k=1,2일때를 이미 모두 돌았기 때문에 
 5-4, 5-1-4, 5-2-4, 5-1-2-4, 5-2-1-4 중에 최솟값으로 dy[5][4]에 이미 반영이 되어있는 것.
 따라서 k=3으로 돌게되면 
 5-3-4, 5-1-3-4, 5-3-1-4, 5-2-3-4, 5-3-2-4, 5-3-1-2-4, 5-1-3-2-4, 5-1-2-3-4, 5-3-2-1-4, 5-2-3-1-4, 5-2-1-3-4
 이 모두 적용되는 것임. 그중 가장 최적한 해(최소비용)로 Relax 갱신되는 것 
 그래서 동적계획법이 좀 어려움 ^^ 
  
 dis[][]의 초기값 : 인접행렬을 기록 (중간에 다른노드를 거치지않고 직행하는데 드는 비용)
 그래프 간선의 무게 = 각 노드로 가는 최소 비용값. 따라서 노드간에 직행간선 없으면 Max(무한)으로 초기화 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, m, a, b, c;
	cin>>n>>m;
	vector<vector<int> > dis(n+1, vector<int>(n+1, 5000));	// M값5000으로 
	for(int i=1; i<=n; i++) dis[i][i]=0;
	for(int i=1; i<=m; i++){
		cin>>a>>b>>c;
		dis[a][b]=c; 
	}// i->j 직통 (그래프초기정보)
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
//				경로까지 출력시에 if문 사용 
//				if(dis[i][j] > dis[i][k] + dis[k][j])
//					dis[i][j] = dis[i][k] + dis[k][j];	// i->k->j 
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	} 
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(dis[i][j] == 5000)
				cout<<"M ";
			else cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}	
