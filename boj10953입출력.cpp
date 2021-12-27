#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, T;
	char ch;
	cin >> T;
	while (T--) {
		cin >> A >> ch >> B;
		cout << A + B << '\n';
	}
	return 0;
}