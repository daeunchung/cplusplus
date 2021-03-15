#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// MAX HEAP with priority_queue 부모가 좌우 자식노드보다 값이 크다.
int main(){
//	freopen("input.txt", "rt", stdin);
	int a;
	priority_queue<int> pQ;
	while(true){
		scanf("%d", &a);
		if(a==-1) break;
		if(a==0){
			if(pQ.empty()) printf("-1\n");
			else{
				printf("%d\n", pQ.top());
				pQ.pop();	
// lib가 자동으로 말단노드를 루트노드로 올려서 
// root를 down-heap(heapify)하여 maxheap구조를 만들어준다. 
			}
		}else pQ.push(a); // 말단노드로 a를 넣어 up-heap하여 maxheap구조 만들어준다. 
	}
	return 0;
}
