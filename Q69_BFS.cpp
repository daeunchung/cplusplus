// 이진트리 넓이우선탐색(BFS) : Level 탐색 => 자료구조 Queue 사용
// Stack 선입후출 Queue 선입선출

// BFS Queue 직접 구현해보기 뺄때 front 넣을때back 
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int Q[100], front=-1, back=-1, ch[10]; // 무방향그래프 체크를 위한 ch배열
vector<int> map[10];	// 인접리스트 
int main(){
	freopen("input.txt", "rt", stdin);
	// 트리이기 때문에 node n 개라면 간선은 n-1 개 
	int i, a, b, x;
	// 인접리스트 생성 
	for(i=1; i<=6; i++){
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	} 
	// 큐 운영 
	Q[++back]=1;
	ch[1]=1;
	// 큐에 깨낼 자료가 남아있으면 계속 돌아 (front==back이면 빈큐)
	// 큐에 한번 들어간 적이 있는 노드는 ch가 1이다. 큐에서 나와도 1이다.
	// 큐에서 나오면 DFS 경로탐색에서 다시 ch를 0으로 돌려줬지만, 큐에서 나오면 다시 ch 0으로 돌려주지 않는다.
	// 이건 경로 탐색이 아니고 단순 BFS 이기 때문에. 출력 한번 했으면 끝 ! 
	while(front<back){
		x=Q[++front];
		printf("%d ", x);	// 큐에서 꺼내고(+출력) for문 자식노드 탐색 
		for(i=0; i<map[x].size(); i++){
			// 큐에 들어간적없는 자식노드들만 큐에 넣어준다. 
			if(ch[map[x][i]]==0){
				ch[map[x][i]]=1;
				Q[++back]=map[x][i];
			}
		}		
	} 
	return 0;
}
