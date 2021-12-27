#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int j = i;
		while (j--)
			cout <<  "*";
		cout << '\n';
	}
	return 0;
}