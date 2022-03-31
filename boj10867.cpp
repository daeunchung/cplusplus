#include <set>
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	set<int> s;
	int n;	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		s.insert(x);
	}
	for (auto i : s)
		cout << i << ' ';

	return 0;
}