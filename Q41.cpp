#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
//	freopen("input.txt", "rt", stdin);
	int i, n, tmp, cnt=0;
	scanf("%d", &n);	tmp=n;
	int sum = 1+2, j=2; 
	while(sum<=n){
		int remain = n-sum;
		int quotient = remain%j;
		if(quotient== 0){
			cnt++;	
			for(i=1; i<j; i++){
				printf("%d + ", i+quotient);
			}printf("%d = %d\n", j+quotient , n);
		}
		j++;
		sum += j;
	}
	printf("%d\n", cnt);
	return 0;
}
// 정답코드도 한번 보시길 ! 내코드보다 변수개수가 적다 
