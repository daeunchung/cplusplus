#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
//	freopen("input.txt", "rt", stdin);
	int i, n, a, check=1;
	stack<int> s;
	scanf("%d", &n);
	vector<char> str;
	
	for(i=1; i<=n; i++){
			scanf("%d", &a);
			s.push(a);
			str.push_back('P');
			while(1){
				if(s.empty()) break;
				// stack이 비어있거나, top이 꺼내야할 수와 같지않으면 break;  
				if(s.top() == check){
					s.pop(); check++; str.push_back('O');
				}else 
					break;
			}
	}
	if(!s.empty()) printf("impossible\n");
	else{
		for(i=0; i<str.size(); i++)
			printf("%c", str[i]);
	}
	return 0;
} 
