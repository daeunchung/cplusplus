#include <stdio.h>
#include <queue>
using namespace std;
int n, map[10][10], dis[10][10];	// dis는 최단거리기록배열
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
struct Loc{
	int x, y;
	Loc(int a, int b){
		x=a; y=b;
	}
};
queue<Loc> Q;
int main(){
	freopen("input.txt", "rt", stdin);
	for(int i=1; i<=7; i++){
		for(int j=1; j<=7; j++){
			scanf("%d", &map[i][j]);
		}
	}
	Q.push(Loc(1, 1));	// 큐에푸시
	map[1][1]=1;		// 들어갔으니 경로를 벽처리
	while(!Q.empty()) {
		Loc tmp = Q.front();
		Q.pop();
		for(int i = 0; i<4; i++){
			int xx = tmp.x+dx[i];
			int yy = tmp.y+dy[i];
			if(map[xx][yy] == 0 && 1<=xx && xx<=7 && 1<=yy && yy<=7){
				Q.push(Loc(xx, yy));
				map[xx][yy] = 1;
				dis[xx][yy] = dis[tmp.x][tmp.y]+1;
			}
		}
	}
	// 큐가 비면 끝나는 것
	printf("%d\n", dis[7][7]);
	return 0;
}


