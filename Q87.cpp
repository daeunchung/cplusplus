//// DFS BFS 둘다 풀수있지만 여기서는 BFS로 푼다 
//// 대각선으로 연결되어있어도 하나의 섬으로 간주 
//// queue가 비면 섬 하나 탐색 완료
//#include <stdio.h>
//#include <queue>
//using namespace std;
//int n, map[30][30], cnt=0;
//int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
//struct Loc{
//	int x, y;
//	Loc(int a, int b){
//		x=a; y=b;
//	}
//};
//queue <Loc> Q;
//int main(){
////	freopen("input.txt", "rt", stdin);
//	int i, j;
//	scanf("%d", &n);
//	for(i = 1; i <= n; i++) for(j = 1; j <= n; j++) scanf("%d", &map[i][j]);
//	for(i = 1; i <= n; i++) {
//		for(j = 1; j <= n; j++) {
//			if(map[i][j]==1){
//				Q.push(Loc(i, j));
//				map[i][j]=0;
//				// BFS //
//				while(!Q.empty()) {
//					Loc tmp = Q.front();
//					Q.pop();
//					for(int i = 0; i<8; i++){
//						int xx = tmp.x + dx[i];
//						int yy = tmp.y + dy[i];
//						if(map[xx][yy]==1){
//							Q.push(Loc(xx, yy));
//							map[xx][yy]=0;
//						}
//					}
//				} 
//				cnt++;	// 섬갯수++ 
//			}	
//		}
//	} 
//	printf("%d\n", cnt);
//	return 0;
//}
