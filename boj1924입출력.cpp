#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int M, D, ans = 0;
	string date[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	cin >> M >> D;

	for (int i = 0; i < M; i++)
	{
		ans += month[i];
	}
	ans += (D - 1);
	cout << date[(1 + ans) % 7] << '\n';
	return 0;
}