#include <stdio.h>
#include <vector>
using namespace std;
// �� �տ� ������ ū���� �? �� Ȯ���ϰ� +1 �ϸ�� 
// �Ʒ� �ڵ�� O(n2)�˰���������, ���������� �̿��ϸ� O(nlogn) �����ϴ�. 
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

