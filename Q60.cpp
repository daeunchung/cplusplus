// 하나의 부분집합을 만들면 자연히 남는 수들로 나머지 부분집합이 만들어진다.  
#include <stdio.h>
using namespace std;
int n, a[11], total=0;
bool flag=false;

void DFS(int L, int sum){
	// 재귀함수에서 return 하면 재귀로 뻗어왔던 함수들이 타고타고 올라가지않고 전부 다 바로 종료 
	if(sum>(total/2)) return;	
	if(sum==(total-sum)){
		flag=true; //return;
	} 
	if(L==n+1){
		if(sum==(total-sum)){
			flag=true; return;
		}
	}
	else{
		DFS(L+1, sum+a[L]);
		DFS(L+1, sum);
	}
}
int main(){
//	freopen("input.txt", "rt", stdin);
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		total+=a[i];
	}
	DFS(1, 0);
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}
