#include <stdio.h>
#include <vector>
using namespace std;
int main(){
//	freopen("input.txt", "rt", stdin);
	int n, i, p1=0, p2=0;
	scanf("%d", &n);
	vector<int> a(n);
	vector<int> nn(n); 
	vector<int> pp(n);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	for(i=0; i<n; i++){
		if(a[i]<0){
			nn[p1++] = a[i];
		}else{
			pp[p2++] = a[i];
		}
	}
	for(i=0; i<p1; i++){
		printf("%d ", nn[i]);
		if(nn[i]==0) break;
	}
	for(i=0; i<p2; i++){
		printf("%d ", pp[i]);
		if(pp[i]==0) break;
	}
	return 0;
}
