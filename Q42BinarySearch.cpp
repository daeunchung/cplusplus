#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* �̺а˻� : 1�����迭�� �ڷḦ ������ ���¿��� 
�迭�� �糡�� ����Ű�� lt=0, rt=7 �� �ʿ� 
mid = (lt+rt)/2;�� �ȴ�. */
int main(){
	freopen("input.txt", "rt", stdin);
	int i, n, key, lt=0, rt, mid, tmp;
	scanf("%d %d", &n, &key);
	vector<int> a;	// a(n) ���� �ٸ��� �޸� ����X �׷��� �ؿ��� push �Ҷ� �������� ��� ���� 
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
