/*
 너무 크고 복잡한 문제를 작게 만들어서 조금 조금씩 크기를 확장해서 해결하는 것
 동적계획법 Bottom-up 방식 
 직관적으로 구할 수 있는 아주 작은 해를 구하고  
 앞의 해를 이용해서 다음 해를 구하고 ...  
 예를 들면 점화식 f(n) = 2 * f(n-1)
 
 1. 동적계획법이란? 네트워크 선 자르기 (Bottom-Up)
 ios_base::sync_with_stdio(false); 동기화 해제했으면 c++표준입출력 cio cout 만 사용해야한다
*/

#include<bits/stdc++.h>
using namespace std;
int dy[50];
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n;
	cin>>n;
	dy[1]=1;
	dy[2]=2;
	for(int i = 3; i<=n; i++){
		dy[i] = dy[i-2] + dy[i-1];
	} 
	cout << dy[n];
	return 0;
}
