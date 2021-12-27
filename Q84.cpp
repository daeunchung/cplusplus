#include <bits/stdc++.h>
// Pre-compiled header  GNU C++의 표준 라이브러리 헤더가 아닙니다. 
// gcc 컴파일러에서 사용되는 헤더이므로, 따로 설정을 해줘야지 사용가능합니다.
using namespace std;
int n, res = -1;
vector<int> T, P;

void DFS(int L, int sum){
	if(L==n+1){
		if(sum>res) res = sum;
	}else{
		if(L+T[L] <= n+1) DFS(L+T[L], sum+P[L]);	// 상담한다.
		DFS(L+1, sum);	// 상담 안한다. 
	}
}
int main(){
	// 입출력속도향상 
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int a, b;
	cin>>n;
	T.push_back(0);	// idx 0 사용X 
	P.push_back(0); // idx 0 사용X
	for(int i=0; i<n; i++){
		cin>>a>>b;
		T.push_back(a);	
		P.push_back(b);
	}
	DFS(1, 0);
	cout<<res;
	return 0; 
}
