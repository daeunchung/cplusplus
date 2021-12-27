/* 7. �˸��ٹٿ� 40���� ����(Bottom-Up)
 DP�� �߿伺 !!!! arr[i][j]�� �����ϴ� ���� �������� ������ �� 
 
 arr[i][j]�� �����ϴ� ��� 2���� : arr[i-1][j]�������ų� �Ǵ� arr[i][j-1]�������ų� 
 dy[i][j] �ǹ� : arr[0][0] ~ arr[i][j] �� ���� �ּ� ����� �ǹ��ϴ� dy�迭 
 dy[0][n], dy[n][0] ������� ������ �� �����ϴ� ���� �Ǳ� ������ ó������ �ʱ�ȭ ���ش�. 
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
	// (0,0), (0,n), (n,0) �� ���� �־��ְ� (1,1)���� DP ���� ���� ����. 
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
