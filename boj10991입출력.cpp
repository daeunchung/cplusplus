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
		int cnt = 0;
		for (int j = 0; j < N-i; j++) cout << ' ';
		while (cnt < i)
		{
			cout << '*' << ' ';
			cnt++;
		}
		if(i != N) cout << '\n';
	}
	return 0;
}