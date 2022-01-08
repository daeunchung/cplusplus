#include <iostream>
using namespace std;
int n, cnt = 1;

int func(int num)
{
	int a = num / 10;
	int b = num % 10;
	if (num == n) return cnt;
	else {
		cnt++;
		return func(10 * b + (a + b) % 10);
	}
}
int main()
{
	cin >> n;
	int a = n / 10;
	int b = n % 10;
	cout << func(10 * b + (a + b) % 10) << '\n';
	return 0;
}