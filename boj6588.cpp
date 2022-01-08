// 21-12-27 
// 에라토스테네스의 체는 루트N 쓸필요 X, check[N-b] == false 가 소수를 뜻하기에 이것만 체크하면 된다
#include <iostream>
using namespace std;
const int MAX = 1000000;
int prime[MAX];
int pn;	// prime 갯수
bool check[MAX + 1];	// 소수 아니면 true로
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	// 에라토스테네스의 체를 한번 돈다
	for (int i = 2; i * i <= MAX; i++)
	{
		if (check[i] == false) {
			prime[pn++] = i;
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i < pn; i++)
		{
			if (check[n - prime[i]] == false)
			{
				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
				break;
			}
		}
	}
	return 0;
}