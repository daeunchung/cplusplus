#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 그냥 풀기 (선택정렬사용X) 
int main(){
//	freopen("input.txt", "rt", stdin); 
	int n, i, cnt=1;
	scanf("%d", &n);
	vector<int> a(n);
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	sort(a.begin(), a.end(), greater<int>());
	int ans=a[0];
	for(i=1; i<n; i++){
		if(ans > a[i]) {
			ans=a[i];
			cnt++;
		}
		if(cnt==3) break;
	}
	printf("%d", ans);
	return 0;
}
