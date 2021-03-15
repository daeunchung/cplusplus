#include <stdio.h>
#include <vector>
#include <algorithm> 
using namespace std;
int main(){
	int i, n, cnt = 0; scanf("%d", &n);
	for(i=1; i<=n; i++){
		int tmp = i;
		while(tmp/10 != 0){
			if(tmp%10 == 3) cnt++;
			tmp/=10;
		}
		if(tmp == 3) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
