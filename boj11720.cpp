#include <iostream>
#include <string>
using namespace std;
int main(){
	int n,ans=0;
	string a;
	cin >> n >> a;
	for(int i=0; i<n; i++){
		ans += a[i];
	}
	cout << ans;
	return 0;
}

