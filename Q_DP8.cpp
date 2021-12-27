/* 8. 알리바바와 40인의 도둑(Top-Down)
 재귀를 사용, 상태트리를 구현 
 DFS(i,j) = min(DFS(i-1,j), DFS(i,j-1)) + arr(i,j); 	위에서 오거나 왼쪽에서 오거나 
 DFS(n,0)은 DFS(n-1,0)만 호출, DFS(0,n)은 DFS(0,n-1)만 호출 ; 가지를 두갈래X 한갈래만 치도록 조건문 걸어야함 
 중복 호출을 방지하기 위해 메모이제이션을 위한 배열 생성 
*/
#include<bits/stdc++.h>
using namespace std;
int arr[21][21], dy[21][21];	// 재귀호출의 메모이제이션을 위한 dy배열 
int DFS(int x, int y){
	if(dy[x][y]>0) return dy[x][y];
	// 메모이제이션(위 코드) 안하면 n값 커지면 Time_Limit_Exceeded 
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
	
