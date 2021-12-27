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
// ��� a[i]���� �� ���Ѱ� rt, ���ÿ� ��ð��߿� �ִ밪�� ã�´�. DVD�ּҿ뷮>=����ð���  
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
/* ���� �˰��� : �̸� ���� �����ϲ���� ���س��� 
�´��� Ȯ�� , �ƴϸ� �̺а˻��� ������ change.
�� ) 123456789�� �־������� ���ϰ��� �ϴ� ���� 
�� ���� �� ���� 45�� �ٴ� �۰� 1���ٴ� ũ��. ��, 1~45 �̺а˻����� mid���� ���̶�� �����ϰ� �ٲ㰡�� 
mid=23 => binary search (�� �������� 23�� ���ϲ���� �����ϴ� ���� �����˰���)
23 �Ǵϱ� �ּҿ뷮 ���ϱ� ���ؼ��� 1~22�� ������ change ...  */ 
