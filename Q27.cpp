#include <stdio.h>
#include <vector>
#include <algorithm> 
using namespace std;
// ���μ����� 
/* 2 3 5 7 .. �Ҽ���θ� �̷���� �迭 ���� X, �׳� n�� ĭ �迭 ����  
	���� ���� Ȯ���ϰ� 0�� �ƴ� ���� ����ϱ� */ 
int main(){
	int i, j, n;	scanf("%d", &n);
	vector<int> a(n+1);	// ���Ǹ� ���� ������� n+1���� 
	for(i=2; i<=n; i++){
		int tmp = i;
		j=2; 
		while(1){
			if(tmp%j==0){
				a[j]++;
				tmp/=j;
			}else j++;
			if(tmp==1) break;								
		}
	} 
	printf("%d! = ", n);
	for(i=2; i<=n; i++){
		if(a[i]!=0) printf("%d ", a[i]);
	}
	return 0;
}
