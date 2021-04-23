#include <iostream>
using namespace std;

int N;

int factorial(int n)
{
	// 입력이 0부터이기 때문에, 만약 n == 1로 할 경우, 무한루프에 빠져 시간초과가 발생
	if (n <= 1) return 1;
	else return n * factorial(n - 1);
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);	
	cin >> N;
	cout << factorial(N) << '\n';
	return 0;
}