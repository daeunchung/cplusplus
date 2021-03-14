#include <stdio.h>
int main(){
	freopen("input.txt", "rt", stdin);
	int a[101], i, j, n, tmp;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
		
	for(i=1; i<n; i++){
		tmp = a[i];
		for(j=i-1; j>=0; j--){
			if(a[j]>=tmp)
				a[j+1] = a[j];
			else
				break;
		}// for문밖으로 나왔으면 이미 j--된 상태이기 때문에 !! a[j+1]=tmp;인 것 
		a[j+1] = tmp;
	}		
	for(i=0; i<n; i++)
		printf("%d ", a[i]);	
	return 0;
}

/* while문으로 하면 
while(j>=0 && a[j]>tmp){
	a[j+1]=a[j];
	j--;
}
a[j+1]=tmp
*/
