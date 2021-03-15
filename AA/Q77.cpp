/* Disjoint-set : 서로소관계의 집합: 자료구조 구현방법 : Tree
make-set(x) : x를 유일한 원소로 하는 새로운 셋을 만듭니다.
union(x, y) : x가 속한 셋과 y가 속한 셋을 합칩니다.
ex) {1, 2} 과 {2, 3} 이 존재하면 교집합{2}가 존재하니 {1, 2, 3} 만들어 내는 것 
find(x) : x가 속한 셋의 대표값(루트노드 값)을 반환합니다.
 학생번호를 노드로 간주하고 친구관계이면 트리의 간선으로 연결 
 1차원 배열을 사용해 트리를 구현 (배열의 idx는 각 학생을 상징) 초기설정 : idx=학생번호  
 unf 배열 : 1번학생=1번집합, 2번학생=2번집합...  
 unf[a]=b; 배열칸안에 다른학생번호(idx값)를 넣음으로 트리연결 */
 
#include <stdio.h>
using namespace std;
int unf[1001];	// 메모이제이션을 위한 배열
 
int Find(int v){ // Find() : v의 집합번호를 반환하는 함수 
	if(v==unf[v]) return v;
//	else return Find(unf[v]); // 1 2 3 4 5 오른쪽 사선트리구조 5가 루트로 반복순회를 많이해야해서 시간 오래걸린다. 
	else return unf[v] = Find(unf[v]);	// 메모이제이션을 통해서 Union&Find 경로압축 (시간훨씬단축) 
}
void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a!=b) unf[a]=b;
}
int main(){
//	freopen("input.txt", "rt", stdin);
	int i, n, m, a, b, fa, fb;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		unf[i]=i;
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		Union(a, b);
	}
	scanf("%d %d", &a, &b);
	fa=Find(a);
	fb=Find(b);
	if(fa==fb) printf("YES\n");
	else printf("NO\n");
	return 0;
}
