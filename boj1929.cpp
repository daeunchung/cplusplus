// 21-12-27
#include <iostream>
using namespace std;
const int MAX = 1000000;
bool check[MAX + 1];
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	check[0] = check[1] = true;
	for (int i = 2; i * i <= MAX; i++)	// 에라's 체는 루트N 안써도 된다고 하셨는데 해설코드는 또 썼네;?
	{
		if (check[i] == false) {
			for (int j = i + i; j <= MAX; j += i)
			{
				check[j] = true;
			}
		}
	}
	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; i++)
	{
		if (check[i] == false) cout << i << '\n';
	}
	return 0;
}