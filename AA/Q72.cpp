#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
//	freopen("input.txt", "rt", stdin);
	int n, k, i;
	scanf("%d %d", &n, &k);
	queue<int> Q;
	for(i=1; i<=n; i++){
		Q.push(i);
	}
	while(Q.size()>1){
		for(i=0; i<k-1; i++){
			int tmp = Q.front(); 
			Q.pop();
			Q.push(tmp);
		}
		Q.pop();
	}
	printf("%d\n", Q.front());
	return 0;
}
