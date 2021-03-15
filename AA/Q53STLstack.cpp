#include <stdio.h>
#include <vector> 
#include <stack>
#include <algorithm>
using namespace std;
int main(){
//	freopen("input.txt", "rt", stdin);
	int n, k;
	stack<int> s;
	char str[20] = "0123456789ABCDEF";
	scanf("%d %d", &n, &k);
	while(n>0){
		s.push(n%k);
		n/=k;
	}
	while(!s.empty()){
		printf("%c", str[s.top()]);	// top() 가장 윗 노드 확인 (참조), 꺼내지 않는다. 
		s.pop();					// pop() 꺼내주는 것 
	}
	return 0;
}
