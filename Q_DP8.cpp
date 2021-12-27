/* 8. �˸��ٹٿ� 40���� ����(Top-Down)
 ��͸� ���, ����Ʈ���� ���� 
 DFS(i,j) = min(DFS(i-1,j), DFS(i,j-1)) + arr(i,j); 	������ ���ų� ���ʿ��� ���ų� 
 DFS(n,0)�� DFS(n-1,0)�� ȣ��, DFS(0,n)�� DFS(0,n-1)�� ȣ�� ; ������ �ΰ���X �Ѱ����� ġ���� ���ǹ� �ɾ���� 
 �ߺ� ȣ���� �����ϱ� ���� �޸������̼��� ���� �迭 ���� 
*/
#include<bits/stdc++.h>
using namespace std;
int arr[21][21], dy[21][21];	// ���ȣ���� �޸������̼��� ���� dy�迭 
int DFS(int x, int y){
	if(dy[x][y]>0) return dy[x][y];
	// �޸������̼�(�� �ڵ�) ���ϸ� n�� Ŀ���� Time_Limit_Exceeded 
	if(x==0 && y==0) return arr[0][0];
	else{
		if(y==0) return dy[x][y] = DFS(x-1, 0) + arr[x][y];
		else if(x==0) return dy[x][y] = DFS(0, y-1) + arr[x][y];
		else return dy[x][y] = min(DFS(x-1,y), DFS(x,y-1)) + arr[x][y];
	}
} 

int main(){
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, cnt = 0;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	cnt = DFS(n-1, n-1);
	cout<<cnt;
	return 0;
}
	
