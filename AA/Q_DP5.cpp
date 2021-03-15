// 5. 최대 선 연결하기 (LIS응용) : 4번 최대부분증가수열과 동일한 문제 -> 변형: 강물이 흐르는데 다리를 만드는 문제로도 변형될 수 있다.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, res=0;
	cin>>n;
	vector<int> arr(n+1), dy(n+1);
	for(int i=1; i<=n; i++)
		cin>>arr[i];
	dy[1]=1;
	for(int i=2; i<=n; i++){
		int max=0;
		for(int j=i-1; j>=1; j--){
			if(arr[j]<arr[i] && dy[j]>max) max=dy[j];
		}
		dy[i]=max+1;
		if(dy[i]>res) res=dy[i];
	}
	cout<<res;
	return 0;
}
