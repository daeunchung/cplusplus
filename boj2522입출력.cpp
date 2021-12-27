#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= N - i; j++) cout << ' ';
		for (int j = N - i + 1; j <= N; j++) cout << '*';
		cout << '\n';
	}
	for (int i = N; i >= 1; i--)
	{
		for (int j = 1; j <= N - i; j++) cout << ' ';
		for (int j = 1; j <= i; j++) cout << '*';
		if(i != 1) cout << '\n';
	}
	return 0;
}