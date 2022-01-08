#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int a, b;
	cin >> a >> b;
	int x1 = a / 100;
	int x2 = (a - 100 * x1) / 10;
	int x3 = a % 10;
	int y1 = b / 100;
	int y2 = (b - 100 * y1) / 10;
	int y3 = b % 10;
	int a1 = 100 * x3 + 10 * x2 + x1;
	int b1 = 100 * y3 + 10 * y2 + y1;
	if (a1 > b1) cout << a1 << '\n';
	else cout << b1 << '\n';
	return 0;
}