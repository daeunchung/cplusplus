#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1000
int n, i, sum;
int p[MAX];
int main() {
	cin >> n;
	for (int i = 0; i<n; i++) 
		cin >> p[i];
	sort(p, p + n);
	for (int i = 0; i<n; i++) {
		sum += p[i] * (n - i);
	}
	cout << sum << '\n';
	return 0;
}