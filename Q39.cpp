#include <stdio.h>
#include <vector>
#include <algorithm> 
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int i, n, m, pa=0, pb=0;
	scanf("%d", &n);	vector<int> a(n);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);	vector<int> b(m);
	for(i=0; i<m; i++)
		scanf("%d", &b[i]);
	vector<int> c(n+m);
	i=0;
	while(n>pa && m>pb){
		if(a[pa] <= b[pb]){
			c[i++] = a[pa++];
		} else if(a[pa] > b[pb]){
			c[i++] = b[pb++];
		} else{
		}
	}
	while(pa<n) c[i++]=a[pa++];
	while(pb<m) c[i++]=b[pb++];
	for(i=0; i<n+m; i++){
		printf("%d ", c[i]);
	}
	return 0;
}
