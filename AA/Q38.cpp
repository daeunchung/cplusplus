#include <stdio.h>
#include <vector>
using namespace std;
int main(){
//	freopen("input.txt", "rt", stdin);
	int n, i, j, idx;
	scanf("%d", &n);
	vector<int> a(n), b(n);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
		
	for(i=0; i<n; i++){
		j=0; idx=0;
		while(1){
			if(b[j++]==0)	// if문 안에 ++있을시 , 조건만족안해도 읽는횟수만큼 j는증가한다 (주의) 
				idx++;
			if(idx == a[i]+1) {
				b[j-1]=i+1; 
				break;
			}
		}
	}
	for(i=0; i<n; i++)
		printf("%d ", b[i]);	
	return 0;
}
