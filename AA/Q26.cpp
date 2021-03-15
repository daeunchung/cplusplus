#include <stdio.h>
#include <vector>
using namespace std;
// 내 앞에 나보다 큰수가 몇개? 를 확인하고 +1 하면됌 
// 아래 코드는 O(n2)알고리즘이지만, 병합정렬을 이용하면 O(nlogn) 가능하다. 
int main(){
	int i, j, n, cnt;	scanf("%d", &n);
	vector<int> a(n);
	for(i = 0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(i = 0; i<n; i++){
		cnt = 1;
		if(i > 0){
			for(j = 0; j<i; j++){
				if(a[j] >= a[i])
					cnt++;
			}
		}
		printf("%d ", cnt);
	}
	return 0;	
}

