/* 에라토스테네스의 체 : 소수(Prime Number) 판별 알고리즘

 대량의 소수를 한꺼번에 판별하고자 할 때 사용한다.  
먼저 소수를 판별할 범위만큼 배열에 할당한 후 인텍스에 해당하는 값을 넣어주고 한개씩 지워나가며 판별
 배열을 돌며 i의 배수들을 지운다. 이때 i 자기자신은 지우지않으며, 이미 지워져있으면 건너뜀 
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, a[200001];
	cin>>n;
	for(int i=2; i<=n; i++) a[i]=i;
	for(int i=2; i<=n; i++){
		if(a[i]==0) continue;
		for(int j=i+i; j<=n; j+=i) a[j]=0;
	}
	for(int i=2; i<=n; i++){
		if(a[i] != 0) cout<<a[i]<<" ";
	}
	return 0;
}
