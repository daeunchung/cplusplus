// nPr 순열구하기 
#include <stdio.h>
using namespace std;
int n, r, cnt=0;
int a[20], res[20], ch[20];	// res:출력할순열 
void DFS(int L){
	if(L==r){
		for(int j=0; j<L; j++){
			printf("%d ", res[j]);
		}
		cnt++;
		puts("");
	}else{
	// 호출이 일어나면 무조건 갈래를 뻗어 
	 	for(int i = 1; i<=n; i++){
	 		if(ch[i]==0){
	 			res[L]=a[i];
	 			ch[i]=1;
	 			DFS(L+1);
	 			ch[i]=0;
			 }
		 }
	}
}
int main(){
//	freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &r);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	DFS(0);
	printf("%d\n", cnt);
	return 0;
}
