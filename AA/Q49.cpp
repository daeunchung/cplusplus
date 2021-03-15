#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int map[11][11], a[11], b[11];
int main(){
//	freopen("input.txt", "rt", stdin);
	int n, i, j, ans=0;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for(i=n; i>=1; i--)
		scanf("%d", &b[i]);
		
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			ans += ( a[i]<b[j] ? a[i] : b[j] );
		}
	}
	printf("%d\n", ans);
	return 0;
}
