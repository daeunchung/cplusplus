#include <stdio.h>
#include <vector>
// �����ڵ忡�� vector �Ⱦ��� pre now ���� �̿���  
int main(){
	int i, n, cnt = 0, max = 0, maxcnt = 0;
	scanf("%d", &n);
	std::vector<int> a(n);
	for(i = 0; i<n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i<n; i++){
		if(a[i] >= max){
			cnt++;
			if(cnt > maxcnt) maxcnt = cnt;
		}else
			cnt = 1;
		max = a[i];
	}
	printf("%d\n", maxcnt);
	return 0;
}
