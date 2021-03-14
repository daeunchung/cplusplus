#include <stdio.h>
#include <vector>
#include <algorithm>	// abs();
using namespace std; 
// 주어지는 정수가 음수일 경우도 있으니 잘 고려해야함  
int main(){
	int i, n, pre, now, pos;	scanf("%d", &n);
	vector<int> a(n);	
	scanf("%d", &pre);
	for(i = 1; i<n; i++){
		scanf("%d", &now);
		pos = abs(pre-now);
		if(0<pos && pos<n && a[pos]==0)
			a[pos]++;
		else{
			printf("NO\n");
			return 0;
		}
		pre = now;
	}
	printf("YES\n");
	return 0;
}

/* 
key : 예를 들어
5
1 4 2 3 7 이 입력되면 1 4, 4 2, 2 3, 3 7 을 비교하지말고
pre=1로 잡고 1 4, 1 2, 1 3, 1 7 로 비교합니다

exit() 함수 : stdlib.h, commit과 같이 프로레스내에 파일 입출력
중인 것을 저장함과 동시에 프로세스종료하여 운영체제에게 권한 넘긴다.
exit(0) 정상종료 EXIT_SUCCESS
exit(1) 에러메시지 종료 EXIT_FAILURE 

return _; _를 실행하고 종료 ****/  

