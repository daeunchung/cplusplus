#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i < 10; i++) {
		
		cout << N << " * " << i << " = " << N*i << '\n';
	}
	return 0;
}