#include<iostream>
using namespace std;
int main() {
	int n, a, max=-1000001, min=1000001;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (a > max) max = a;
		if (a < min) min = a;
	}
	cout << min << ' ' << max;

	return 0;
}