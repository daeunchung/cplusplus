#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, X;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num < X) cout << num << ' ';
	}
	return 0;
}