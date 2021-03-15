#include <stdio.h>
#include <vector>
// 시간초과방지를 위해 단일for문 안에서 해결하기 
// (하나의 변수 sum에 새값만큼 더해주고 헌값만큼 빼주기, 한칸한칸 앞으로 전진) 
int main(){
	int i, n, m, sum = 0, max = -200;
	scanf("%d %d", &n, &m);
	std::vector<int> t(n);	// std라는 객체로 vector 배열을 만듬 (초기값은 기본0으로 되어있음) 
	for(i = 0; i<n; i++){
		scanf("%d", &t[i]);
	} 
	for(i = 0; i<m; i++){
		sum += t[i];
	}
	max = sum;
	for(i = m; i<n; i++){
		sum = sum + t[i] - t[i-m];
		if(sum > max)
			max = sum;
	}
	printf("%d\n", max);
	return 0;
}
