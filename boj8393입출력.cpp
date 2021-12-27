#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int N, ans = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		ans += i;
	}
	cout << ans << '\n';
	return 0;
}