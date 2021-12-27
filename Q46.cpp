#include <iostream>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int i, n, k, cnt=0, pos=0, total=0;
	cin>>n;
	vector<int> a(n+1);
	for(i=1; i<=n; i++){
		cin>>a[i];
		total += a[i];
	}
	cin>>k;
	if(k>=total){
		cout<<"-1\n";
		return 0;
	}
	while(1){
		pos++;
		if(pos>n) pos=1;
		if(a[pos]==0) continue;
		else if(a[pos]>0){
			a[pos]--;
			cnt++;
			if(cnt==k+1){				
				cout<<pos;
				break;
			}		
		}
	}
	return 0;
}
