#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[1001], n;
int Count(int s){
	int i, cnt=1, sum=0;
	for(i=1; i<=n; i++){
		if(sum+a[i]>s){
			cnt++;
			sum=a[i];
		}else
			sum+=a[i];
	}
	return cnt;
}
int main(){
//	freopen("input.txt", "rt", stdin);
	int m, i, lt=1, rt, mid, res, max=-2147000000;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		rt=rt+a[i];	
// 모든 a[i]값을 다 더한게 rt, 동시에 곡시간중에 최대값도 찾는다. DVD최소용량>=최장시간곡  
		if(a[i]>max) max=a[i];
	}
	while(lt<=rt){
		mid=(lt+rt)/2;
		if(mid>=max && Count(mid)<=m){
			res=mid;
			rt=mid-1;
		}else
			lt=mid+1;
	}
	printf("%d\n", res);
	return 0;
}
/* 결정 알고리즘 : 미리 답이 무엇일꺼라고 정해놓고 
맞는지 확인 , 아니면 이분검색의 범위를 change.
예 ) 123456789가 주어졌으면 구하고자 하는 답은 
수 들의 총 합인 45보 다는 작고 1보다는 크다. 즉, 1~45 이분검색으로 mid값이 답이라고 가정하고 바꿔가기 
mid=23 => binary search (이 과정에서 23이 답일꺼라고 가정하는 것이 결정알고리즘)
23 되니까 최소용량 구하기 위해서는 1~22로 범위를 change ...  */ 
