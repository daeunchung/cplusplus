#include <stdio.h>
#include <vector>
#include <algorithm> 
using namespace std;
int main(){
	int i, j, n, two = 0, five = 0;	scanf("%d", &n);
	for(i=2; i<=n; i++){
		int tmp = i;
		j=2; 
		while(1){
			if(tmp%j==0){
				if(j==2) two++;
				else if(j==5) five++;
				tmp/=j;
			}else j++;
			if(j>5 || tmp==1) break;								
		}
	} 
	printf("%d\n", two>five ? five : two );
	return 0;
}
