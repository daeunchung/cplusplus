#include <iostream>
using namespace std;

int N;
int fibo(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		return fibo(n - 1) + fibo(n - 2);
	}
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> N;
	cout << fibo(N) << '\n';
	return 0;
}