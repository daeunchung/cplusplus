/* 11. 최대점수 구하기 (냅색 알고리즘) 
9번 10번과 다름. 한 유형당 한개만 풀 수 있다는 조건 때문에 dy[][] 를 2차원배열로 잡아야한다. 
dy[i][j] = dy[i-1][j-pt];	i:문제종류 j:제한시간 ps:문제점수 pt:문제시간 

그러나 dy를 2차원 배열로 잡으면 공간복잡도가 상당하다. 
 => 1차원배열 dy로 하는법이 있음. 바로 뒤에서 부터 순환하는 것 
 초기값 0으로 초기화, 뒤에서부터 dy[idx] idx=pt;일때까지 돈다.  
 dy[idx] = dy[idx-pt]+ps; 이것을 뒤에서 부터 순회하며 앞을 참조하기에 중복되는 일 X 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, m, ps, pt;
	cin>>n>>m;
	vector<int> dy(m+1);
	for(int i=0; i<n; i++){
		cin>>ps>>pt;
		for(int j=m; j>=pt; j--){
			dy[j]=max(dy[j], dy[j-pt]+ps);
		}
	}
	cout<<dy[m];
	return 0;
}
