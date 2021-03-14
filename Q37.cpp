#include <stdio.h>
// pos : 캐시에 수가 있는지 없는지 체크, 있으면 해당 idx 없으면 -1 반환
int C[20];	// 3 <= Cachesize <= 10 
int main(){
//	freopen("input.txt", "rt", stdin);
	int s, n, a, i, j, pos;
	scanf("%d %d", &s, &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a);
		pos=-1;
		for(j=0; j<s; j++) if(C[j] == a) pos = j;
		if(pos == -1){	// cache miss
			for(j=s-1; j>0; j--)
				C[j] = C[j-1];
		}else{			// cache hit
			for(j=pos; j>0; j--)
				C[j] = C[j-1];
		}
		C[j]=a;	// C[0]=a;
	}
	for(i=0; i<s; i++) printf("%d ", C[i]); 	
	return 0;
}
