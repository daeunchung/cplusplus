#include <stdio.h>
#include <vector>
using namespace std;
// �������� �ϸ� ������� �������� �ٲ������� ������ �ȵȴ�.
// ���� �յڼ��ڳ��� ���ؼ� �ڸ� �ٲٴ� ���������� �����ϴ�. 
int main(){
	freopen("input.txt", "rt", stdin);
	int n, idx, i, j, tmp;
	scanf("%d", &n);
	vector<int> a(n); 
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	for(i=0; i<n; i++){
		for(j=0; j<n-i-1; j++){
			if(a[j]>0 && a[j+1]<0) {
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
