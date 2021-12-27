/* 52. Ugly Numbers (투포인트 알고리즘 응용) 
하... 왜 이렇게 어렵나 했더니 DP문제네.. *^^* 정말 ^^ 휴 ~ DP가 제일어렵다 ~ 

a[i]는 i번째 Ugly Number 를 의미 
a[p2]*2, a[p3]*3, a[p5]*5 중에 최솟값을 a[]에 넣어주는것. 앞에서 넣어준 a[i]가 a[i+1]에 반영되기에 동적계획법 이다.
a[i]에 넣어줄 최솟값이 된 pointer(p2, p3, p5) 를++ 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, i, p2, p3, p5, min=0;
	cin>>n;
	vector<int> a(n+1, 0);
	a[1]=1;
	p2=p3=p5=1;	
	for(i=2; i<=n; i++){
		if(a[p2]*2 < a[p3]*3) min=a[p2]*2;
		else min=a[p3]*3;
		if(a[p5]*5 < min) min=a[p5]*5;
		if(min==a[p2]*2) p2++;
		if(min==a[p3]*3) p3++;
		if(min==a[p5]*5) p5++;
		a[i]=min;
	} 
	printf("%d\n", a[n]);
	return 0;
} 
