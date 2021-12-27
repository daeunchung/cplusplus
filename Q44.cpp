#include <stdio.h>
#include <vector>
#include <algorithm> 
using namespace std;
int n;
int Count(int len, int *a){	// 매개변수: 답으로 가정한(결정알고리즘) 두말사이 최대거리, 이중검색하는 배열 
	int i, cnt=1, pos=a[1];	// a[1]마구간에 말 한마리 있어서 초기 cnt=1; 
	for(i=2; i<=n; i++){
		if(a[i]-pos >= len){
			cnt++;
			pos=a[i];
		}
	}
	return cnt;
}
int main(){
//	freopen("input.txt", "rt", stdin);
	int m, i, lt=1, rt, mid, res;
	scanf("%d %d", &n, &m);

	int *a = new int[n+1]; // 0~n 배 
//	vector<int> a(n+1);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	sort(a+1, a+n+1);	// vector가 아닌 배열을 정렬할때 내용들어있는 구간만 정렬 
//	sort(a.begin(), a.end());

// 가장 가까운 두 말의 최대거리는 1 ~ 정렬한후의 a[n] 사이에 존재 : 여기서 이분검색 => 첫 rt를 a[n]가장끝놈으로 잡아준 것 
	rt = a[n];
	while(lt<=rt){
		mid = (lt+rt)/2;
		if(Count(mid, a) >= m){
			res = mid;
			lt = mid+1;	
		}else
			rt = mid-1;
	}
	printf("%d\n", res);
	delete[] a;
	return 0;
}
