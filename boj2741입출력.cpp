#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cout << i << '\n';
	}
	return 0;
}