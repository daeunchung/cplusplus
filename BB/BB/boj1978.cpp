#include <iostream>
using namespace std;
int main() {
	int n, cnt=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int flag = 1;
		int num; cin >> num;
		if (num == 1) continue;
		for (int j = 2; j*j <= num; j++) {
			if (num % j == 0) {
				flag = -1;
				break;
			}
		}
		if (flag == 1) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}