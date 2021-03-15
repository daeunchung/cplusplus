#include <stdio.h>
#include <vector>
// 정답코드에선 vector 안쓰고 pre now 값을 이용함  
int main(){
	int i, n, cnt = 0, max = 0, maxcnt = 0;
	scanf("%d", &n);
	std::vector<int> a(n);
	for(i = 0; i<n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i<n; i++){
		if(a[i] >= max){
			cnt++;
			if(cnt > maxcnt) maxcnt = cnt;
		}else
			cnt = 1;
		max = a[i];
	}
	printf("%d\n", maxcnt);
	return 0;
}
