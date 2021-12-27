/* 7. 알리바바와 40인의 도둑(Bottom-Up)
 DP의 중요성 !!!! arr[i][j]에 도착하는 것을 기준으로 생각할 것 
 
 arr[i][j]에 도착하는 방법 2가지 : arr[i-1][j]에서오거나 또는 arr[i][j-1]에서오거나 
 dy[i][j] 의미 : arr[0][0] ~ arr[i][j] 로 가는 최소 비용을 의미하는 dy배열 
 dy[0][n], dy[n][0] 내용들은 한줄을 쭉 누적하는 합이 되기 때문에 처음부터 초기화 해준다. 
 dy[i][j] = min(dy[i-1][j], dy[i][j-1]) + arr[i][j];
*/
#include<bits/stdc++.h>
using namespace std;
int arr[21][21], dy[21][21];
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
	// (0,0), (0,n), (n,0) 을 먼저 넣어주고 (1,1)부터 DP 도는 것이 좋다. 
	dy[0][0] = arr[0][0];
	for(int i=0; i<n; i++){
		dy[0][i] = dy[0][i-1] + arr[0][i];
		dy[i][0] = dy[i-1][0] + arr[i][0];
	}
	for(int i=1; i<n; i++){
		for(int j=1; j<n; j++){
 			dy[i][j] = min(dy[i-1][j], dy[i][j-1]) + arr[i][j];
		}
	}
	cout << dy[n-1][n-1];
	return 0;
}
