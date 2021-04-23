#include <iostream>
using namespace std;

unsigned long long N;

void DecToBinary(unsigned long long n)
{
	if (n != 1) DecToBinary(n / 2);
	cout << (n % 2);
}
int main() {
	cin >> N;
	DecToBinary(N);
	cout << '\n';
	return 0;
}