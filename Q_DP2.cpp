/*
 2. 네트워크 선 자르기 (Top-Down : 재귀, 메모이제이션) 
 앞전에 미리 구해진 것을 '기록'해서 다음 호출에서 가닥이 뻗을때에 Cut Edge
 메모를 해놓고 불필요한 재귀호출을 방지 
*/
#include<bits/stdc++.h>
using namespace std;
int dy[101];	// Edge cut 을 위한 메모이제이션 table 
int DFS(int n){
	// 아래 if문을 통해 Edge cut 수행. 안해주면 n값커지면 runtime 겁.나.오래걸림 
	if(dy[n]>0) return dy[n];
	
	if(n==1 || n==2) return n;
	else return dy[n] = DFS(n-1) + DFS(n-2);
}

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	cout << DFS(n);
	return 0;
}
