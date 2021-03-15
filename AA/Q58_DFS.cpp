#include <iostream>       
#include <vector>
#include <algorithm>
using namespace std;

// 이진 트리 생성 
void D(int v){
	if(v>7) return;
	else{
		D(v*2);
		D(v*2+1);
		printf("%d ", v);	// 후위순회 
	}
}
int main(){
//	freopen("input.txt", "rt", stdin);
	D(1); 
	return 0;
}

/*
출력하는 일 printf("%d ", v); 을 함수 자신이 해야하는 일 이라고 표현하면
void D(int v){
	if(v>7) return;
	else{
		printf("%d ", v);	// 전위순회 
		D(v*2);
		printf("%d ", v);	// 중위순회 
		D(v*2+1);
		printf("%d ", v);	// 후위순회 - 병합정렬(좌우 자식노드 먼저 처리하고 자신의 일을 하는) 시 아주 중요 
	}
}
*/
 
