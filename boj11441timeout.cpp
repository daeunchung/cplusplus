//#include <stdio.h>
#include <iostream>
using namespace std;

// 이중for문으로 시간초과 ( 시간제한 1초) 
int i, j, n, m, s, e;
int main(){
	cin >> n;
	int *a = new int[n];
	for(i = 0; i<n; i++)
		cin >> a[i];
	cin >> m;
	int *b = new int[m];
	fill_n(b, m, 0);
	for(i = 0; i<m; i++){
		cin >> s >> e;
		for(j = s-1; j<e; j++){
			b[i] += a[j];
		}
	}
	for(i = 0; i<m; i++)
		cout << endl << b[i];
	delete[] a, b;
	return 0;	
}
