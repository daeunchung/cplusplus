/* 52. Ugly Numbers (������Ʈ �˰��� ����) 
��... �� �̷��� ��Ƴ� �ߴ��� DP������.. *^^* ���� ^^ �� ~ DP�� ���Ͼ�ƴ� ~ 

a[i]�� i��° Ugly Number �� �ǹ� 
a[p2]*2, a[p3]*3, a[p5]*5 �߿� �ּڰ��� a[]�� �־��ִ°�. �տ��� �־��� a[i]�� a[i+1]�� �ݿ��Ǳ⿡ ������ȹ�� �̴�.
a[i]�� �־��� �ּڰ��� �� pointer(p2, p3, p5) ��++ 
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
