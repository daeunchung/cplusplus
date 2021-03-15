#include <iostream>
using namespace std;
int main() {
	int a[9], flag = 0;
	for(int i=1; i<9; i++)
		cin >> a[i];
	for (int i = 1; i < 9; i++) {
		if (a[i] == i && (flag == 0 || flag == 1)) flag = 1;
		else if (a[i] == 9 - i && (flag == 0 || flag == 2)) flag = 2;
		else {
			flag = 3;
			break;
		}
	}
	if (flag == 1) cout << "ascending" << '\n';
	else if (flag == 2) cout << "descending" << '\n';
	else if (flag == 3) cout << "mixed" << '\n';
	return 0;
}
