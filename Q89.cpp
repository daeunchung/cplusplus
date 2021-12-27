// Blood Kill ?
/* 익은1 익지않은0 빈칸-1   토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 
처음부터 모두 1이면 0출력 
토마토가 모두 익지는 못하는 상황이면 -1 출력*/
#include <stdio.h>
#include <queue>
using namespace std; 
int m, n, tom[1010][1010], dis[1010][1010], res=-2147000000;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
struct Loc{
	int x, y;
	Loc(int a, int b){
		x=a; y=b;
	}
};
queue <Loc> Q;
int main(){
//	freopen("input.txt", "rt", stdin);
	scanf("%d %d", &m, &n);
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			scanf("%d", &tom[i][j]);
			// 첫 입력받으면서 익은 토마토들을 순차적으로 큐에 넣어주는게 가장 중요한 문제
			if(tom[i][j]==1) Q.push(Loc(i, j));
		}
	}
	while(!Q.empty()) {
		Loc tmp = Q.front();
		Q.pop();
		for(int i = 0; i<4; i++){
			int xx = tmp.x+dx[i];
			int yy = tmp.y+dy[i];
			if(tom[xx][yy] == 0){
				if(1<=xx && xx<=n && 1<=yy && yy<=m){
					Q.push(Loc(xx, yy));
					tom[xx][yy] = 1;
					dis[xx][yy] = dis[tmp.x][tmp.y]+1;
				}
			}
		}
	} // 모든 BFS 종료
	
	int f=1;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if(tom[i][j] == 0) f = 0;
		}
	} 
	
	if(f == 1){	// 다익었으면 dis배열값중 최댓값 찾아서 출력 
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=m; j++){
				if(res<dis[i][j]) res = dis[i][j];	
			}
		}
		printf("%d\n", res); 
	}
	else printf("-1"); // 안익은토마토 존재 
	return 0;
}

