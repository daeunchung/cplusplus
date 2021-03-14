#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 이분검색 : 1차원배열에 자료를 정렬한 상태에서 
배열의 양끝을 가리키는 lt=0, rt=7 가 필요 
mid = (lt+rt)/2;이 된다. */
int main(){
	freopen("input.txt", "rt", stdin);
	int i, n, key, lt=0, rt, mid, tmp;
	scanf("%d %d", &n, &key);
	vector<int> a;	// a(n) 때와 다르게 메모리 생성X 그러나 밑에서 push 할때 동적으로 잡는 것임 
	for(i=0; i<n; i++){
		scanf("%d", &tmp);
		a.push_back(tmp); 
	}
	sort(a.begin(), a.end());
	
	rt=n-1;
	while(lt<=rt){
		mid = (lt+rt)/2;
		if(a[mid]==key){
			printf("%d\n", mid+1);
			return 0;
		}else if(a[mid]>key) rt=mid-1;
		else lt=mid+1;
	}
	return 0;
}
