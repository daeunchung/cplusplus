/*
 최대부분증가수열
 1차원배열 -> python 1차원 리스트 

 풀이 : arr[i]를 마지막 항으로 갖는 증가수열을 생각해본다. 

 dy[i] 의 의미 : arr[i]가 내가 만들고자하는 부분증가수열의  
 마지막 항일 때에 만들어지는 수열들 중에 가장 긴 수열의 길이 
 
 최종적으로 dy[i]중 최댓값을 답으로 출력 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, res=0;
	cin>>n;
	vector<int> arr(n+1), dy(n+1);	// 0으로 초기화
	for(int i = 1; i<=n; i++)
		cin>>arr[i];
	// 최대부분증가수열은 dynamic 2중for문 
	dy[1]=1;	// DP Bottom-Up
	for(int i = 2; i<=n; i++){	
		int max = 0;
		for(int j = 1; j<i; j++){	// for(int j=i-1; j>=1; j--)
			if(arr[j]<arr[i] && dy[j]>max){
				max=dy[j];
			}
		}
		dy[i] = max+1;
		if(dy[i]>res) res=dy[i];
	}
	cout<<res;
	return 0;
}

