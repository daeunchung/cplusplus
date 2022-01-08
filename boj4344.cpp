#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;	cin >> T;

	cout << fixed;
	cout.precision(3);
	while (T--)
	{
		int n;	cin >> n;
		int cnt = 0, tot = 0;
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			tot += v[i];
		}
		float avg = tot / (float)n;
		for (int i = 0; i < n; i++) {
			if (v[i] > avg) cnt++;
		}
		cout << cnt / (float)n * 100 << '%' << '\n';
	}
	return 0;
}
