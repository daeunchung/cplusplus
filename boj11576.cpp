// Base Conversion
// 2 * 17 ^ 1 + 16 * 17 ^ 0
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int A, B, cnt, num;		long long baseTen = 0;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> A >> B >> cnt;
	while (cnt--)
	{
		cin >> num;
		baseTen += num * pow(A, cnt);
	}
	while (baseTen > 0)
	{
		v.push_back(baseTen % B);
		baseTen /= B;
	}
	reverse(v.begin(), v.end());
	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it << ' ';
	return 0;
}
