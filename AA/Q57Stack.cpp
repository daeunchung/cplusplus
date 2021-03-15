#include <iostream>       
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
//	freopen("input.txt", "rt", stdin);
	int i=0, n;
	stack<int> s;
	scanf("%d", &n);
	while(n/2 != 0){
		s.push(n%2);
		n/=2;
	}
	s.push(n);
	while(!s.empty()){
		printf("%d", s.top());
		s.pop();
	}
	return 0;
}
