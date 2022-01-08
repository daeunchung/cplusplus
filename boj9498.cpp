#include <iostream>
using namespace std;
int main(){
	int n; cin >> n;
	if (n / 10 == 10 || n / 10 == 9) cout << 'A' << '\n';
	else if (n / 10 == 8) cout << 'B' << '\n';
	else if (n / 10 == 7) cout << 'C' << '\n';
	else if (n / 10 == 6) cout << 'D' << '\n';
	else cout << 'F' << '\n';
	return 0;
}