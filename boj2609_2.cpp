#include <iostream>
using namespace std;
// gcd with recursion
int gcd(int x, int y)
{
	if (y == 0) return x;
	else return gcd(y, x % y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b;
	cin >> a >> b;
	int g = gcd(a, b);
	cout << g << '\n' << a * b / g << '\n';
	return 0;
}