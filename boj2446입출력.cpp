#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N-1; i++)
	{
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < 2 * (N - i) - 1; j++) cout << '*';
		cout << ' ' << '\n';
	}
	for (int i = N-1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 0; j < 2 * (N - i) - 1; j++) cout << '*';
		if (i != 0) cout << ' ' << '\n';
	}
	return 0;
}