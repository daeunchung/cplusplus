// 67 과 동일한 문제 
// DFS : 가중치 방향그래프 인접리스트
#include <stdio.h>
#include <vector>
//#define x first
//#define y second : first, second 대신 x, y를 사용하고 싶으면 define 
using namespace std;
int ch[30], cnt=0, n, cost=2147000000;
vector<pair<int, int> > map[30];

void DFS(int v, int sum){
	int i;
	if(v==n) {
		if(cost>sum) cost=sum;	
	}
	else{
		for(i=0; i<map[v].size(); i++){
			if(ch[map[v][i].first]==0){
				ch[map[v][i].first]=1;
				DFS(map[v][i].first, sum+map[v][i].second);
				ch[map[v][i].first]=0;
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
		map[a].push_back(make_pair(b, c));
	}
	ch[1]=1;
	DFS(1, 0);
	printf("%d\n", cost);
	return 0;
}
/* Pair 자료구조는 두개의 데이터형을 한쌍으로 묶는다. 
Utility.h에 정의되어있는데 <vector, algorithm>이 이미 포함하고 있기때문에 따로 include필요X 
pair<int, int> p;  pair 자료구조의 p 객체 생성
접근은 p.first, p.second 로, 내용 담을 메모리 생성은 make_pair( , ) 로 */

