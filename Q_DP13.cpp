/* 13. 회장뽑기 (플로이드-와샬 응용) 
 가중치값이 모두 1인 무방향가중치 그래프에서 최단거리 계산한다고 생각하면 됌
 dis[][] 배열에서 dis[i][] 값들중에 최댓값이  i번 회원의 회원점수이다.
 dis배열을 완성할때 모든 정점에서 모든 정점으로의 최단거리 구해서 채운다. 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, a, b;
	cin>>n;
	vector<vector<int> > dis(n+1, vector<int>(n+1, 100));
	vector<int> res(n+1);
	for(int i=1; i<=n; i++) dis[i][i]=0;
	while(true){
		cin>>a>>b;
		if(a==-1 && b==-1) break;
		dis[a][b]=1;
		dis[b][a]=1;
	}
//	while(a!=-1 && b!=-1){
//		cin>>a>>b;
//		dis[a][b]=1;
//		dis[b][a]=1;
//	} 이건 왜 안될까 ? 
	// 플로이드-와샬 // for(int k가 1~n 까지){ 이중for문 } => 삼중for문 
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	///////////////////////////////////////////////////////////////////
	int score=100;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j) continue;
			res[i]=max(res[i], dis[i][j]);			
		}
		score=min(score, res[i]);
	}
	
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(res[i]==score) cnt++;
	}
	cout<<score<<" "<<cnt<<endl;
	for(int i=1; i<=n; i++){
		if(res[i]==score) cout<<i<<" ";
	}
	return 0;
} 
