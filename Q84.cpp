#include <bits/stdc++.h>
// Pre-compiled header  GNU C++�� ǥ�� ���̺귯�� ����� �ƴմϴ�. 
// gcc �����Ϸ����� ���Ǵ� ����̹Ƿ�, ���� ������ ������� ��밡���մϴ�.
using namespace std;
int n, res = -1;
vector<int> T, P;

void DFS(int L, int sum){
	if(L==n+1){
		if(sum>res) res = sum;
	}else{
		if(L+T[L] <= n+1) DFS(L+T[L], sum+P[L]);	// ����Ѵ�.
		DFS(L+1, sum);	// ��� ���Ѵ�. 
	}
}
int main(){
	// ����¼ӵ���� 
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int a, b;
	cin>>n;
	T.push_back(0);	// idx 0 ���X 
	P.push_back(0); // idx 0 ���X
	for(int i=0; i<n; i++){
		cin>>a>>b;
		T.push_back(a);	
		P.push_back(b);
	}
	DFS(1, 0);
	cout<<res;
	return 0; 
}
