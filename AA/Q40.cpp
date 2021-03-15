#include <iostream>
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
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> c(n>m ? m : n);
	
	int pc=0;
	while(n>pa && m>pb){
		if(a[pa] < b[pb]) 
			pa++;
		else if(a[pa] > b[pb]) 
			pb++;
		else {
			c[pc++] = a[pa++]; pb++;
		}
	}
	for(i=0; i<pc; i++){
		printf("%d ", c[i]);
	}
	return 0;
}
