#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
//	freopen("input.txt", "rt", stdin);
	int i, n, num, cnt=1, a;
	scanf("%d %d", &n, &num);
	for(i=0; i<n; i++){
		scanf("%d", &a);
		if(a<num){
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
