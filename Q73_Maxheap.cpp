#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// MAX HEAP with priority_queue �θ� �¿� �ڽĳ�庸�� ���� ũ��.
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
// lib�� �ڵ����� ���ܳ�带 ��Ʈ���� �÷��� 
// root�� down-heap(heapify)�Ͽ� maxheap������ ������ش�. 
			}
		}else pQ.push(a); // ���ܳ��� a�� �־� up-heap�Ͽ� maxheap���� ������ش�. 
	}
	return 0;
}
