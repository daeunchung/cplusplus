#include <stdio.h>
#include <vector>
using namespace std;
// 삽입정렬 하면 양수음수 순서까지 바뀌어버리기 때문에 안된다.
// 따라서 앞뒤숫자끼리 비교해서 자리 바꾸는 버블정렬이 적합하다. 
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
