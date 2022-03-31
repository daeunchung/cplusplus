#include <iostream>
using namespace std;
int numcnt[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	int n; 
	cin >> n; 

	for (int i = 0; i < n; i++) { 
		int c;
		cin >> c; 
		numcnt[c]++;
	} 
	for (int i = 1; i < 10001; i++) { 
		for (int j = 0; j < numcnt[i]; j++) {
			cout << i << '\n'; 
		} 
	}
	return 0;
}