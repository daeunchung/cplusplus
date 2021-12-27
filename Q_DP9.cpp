/* 9. 가방문제 (냅색 알고리즘 : Knapsack algorithm) 
 i for문 : 돌 종류를 한가지씩 추가
 j for문 : 
  idx j = 가방에 담는 무게 (kg) 
  dy[j] = 가방에 j무게(kg) 담을 때에 보석의 최대 가치 

  dy[j] = dy[j-w] + v; 만약 기존의 dy[j]보다 크면 값 갱신 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, m, w, v;
	cin>>n>>m;
	vector<int> dy(m+1, 0);
	for(int i=0; i<n; i++){
		cin>>w>>v;
		for(int j=w; j<=m; j++){
			dy[j]=max(dy[j], dy[j-w]+v);
		}
	}
	cout<<dy[m];
	return 0;
}
