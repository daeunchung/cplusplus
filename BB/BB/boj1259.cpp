#include <iostream>
using namespace std;
int n, arr[5], j, flag;
int main() {
	while (1) {
		cin >> n;
		if (n == 0) break;
		arr[5] = { 0, };
		while (n != 0) {
			flag = 1;
			j = 4;
			while (n != 0) {
				arr[j] = n % 10;
				n /= 10;
				j--;
			}
		}
		j++;
		for (int k = 0; k < (5 - j) / 2; k++) {
			if (arr[j + k] != arr[4 - k]) {
				flag = -1;
				break;
			}
		}
		if (flag == -1) cout << "no" << endl;
		else if (flag == 1)cout << "yes" << endl;
	}
	return 0;
}