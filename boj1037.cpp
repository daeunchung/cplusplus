#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);

	int n;
	cin >> n;
	int mx = -1;
	int mn = 2147483647;
	for (int i = 0; i < n; i++) {
		int x;	cin >> x;
		if (mx < x) mx = x;
		if (mn > x) mn = x;
	}
	cout << mn * mx << '\n';
	return 0;
}

// Sol 2
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << (*v.begin()) * (*(v.end()-1)) << '\n';
	return 0;
}