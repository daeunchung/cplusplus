// 68 과 동일한 문제 
// DFS : 가중치 방향그래프 인접행렬
#include <stdio.h>
using namespace std;
int map[30][30], ch[30], n, cost=2147000000;	// cost 변수명 min으로 하면 에러나는 이유 아래에 !!! 

void DFS(int v, int sum){
	int i;
	if(v==n) {
		if(cost>sum) cost=sum;	
	}
	else{
		for(i=1; i<=n; i++){
			if(map[v][i]>0 && ch[i]==0){
				ch[i]=1;
				DFS(i, sum+map[v][i]);
				ch[i]=0;
			}
		}
	}
}

int main(){
//	freopen("input.txt", "rt", stdin);
	int i, m, a, b, c;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a][b]=c;
	}
	ch[1]=1;
	DFS(1, 0);
	printf("%d\n", cost);
	return 0;
}

// [Error] reference to 'min' is ambiguous ([에 러] 전역 변수 'min' 모호합니다) 
// -> namespace std 안에 C++ 함수인 max 함수가 존재하기 때문
// int max 대신 int maxx 이런식으로 변수명 변경하면 된다.  min도 마찬가지 minn 또는 최소비용이니 cost로 변수명 변경 

// 그래프 DFS 연습을 위해 이렇게 푸는 것 뿐
// 1->N 으로 가는 간단한 다익스트라 알고리즘  찾.아.보.시.길 !! 
