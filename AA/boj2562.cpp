#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	
	int max=-1, n;
	vector<int> a(9);
	for(int i=0; i<9; i++) {
		cin>>a[i];
		if(a[i]>max){
			max = a[i]; n=i;
		}	
	}
	cout<<max<<endl<<n+1;
    return 0; 
}
