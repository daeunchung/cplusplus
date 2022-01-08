#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	cin >> a >> b;
	int i = b % 10;
	int j = b % 100 / 10;
	int k = b / 100;
	cout << a * i << '\n';
	cout << a * j << '\n';
	cout << a * k << '\n';
	cout << a * (i + 10 * j + 100 * k) << '\n';
	return 0;
}