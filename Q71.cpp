#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int ch[10001], d[3]={-1, 1, 5};
// ch[] : 거리배열 겸 방문여부체크배열 
int main(){
//	freopen("input.txt", "rt", stdin);
	int s, e, x, i, pos;
	queue<int> Q;
	scanf("%d %d", &s, &e);
	ch[s]=1;	// 출발지점을 0아니라 1로 지정해서  
	Q.push(s);
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		for(i=0; i<3; i++){
			pos=x+d[i];
			if(pos<=0 || pos>10000) continue;
			if(pos==e){
				printf("%d\n", ch[x]);	// 여기서 바로 전단계인 ch[x] 출력
				exit(0);	// 프로그램 종료 
			}
			if(ch[pos]==0){
				ch[pos]=ch[x]+1;
				Q.push(pos);
			} 
		}
	}
	return 0;
}
