#include <stdio.h>
#include <vector>
using namespace std;
int ch[101];	// check array 
int main(){
	freopen("input.txt", "rt", stdin);
	int ms, n, i, j, k, p;
	scanf("%d %d", &ms, &n);
	vector<int> m(ms);

	for(i=0; i<n; i++){
		scanf("%d", &p);
		if(ch[p] == 0){		// first time
			for(j=ms-1; j>0; j--)
				m[j] = m[j-1];
			ch[p] = 1;
		}else if (ch[p] == 1){	// been here before
			for(j=0; j<ms; j++){
				if(m[j] == p){
					for(k=j; k>0; k--)
						m[k] = m[k-1];
				}
			}
		}
		m[0] = p;
	}
	for(i=0; i<ms; i++){
		printf("%d ", m[i]);
	}
	return 0;
} 

/* 이 코드가 틀린 이유 ?
=> 한번 들어왔던 수는 캐시 메모리를 나간 후에도 계속 
check array 에 1로 표시되어 현재 캐시 메모리에 없어도 들어와있다고 
표시되기 때문. */ 
