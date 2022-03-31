#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s1, s2, ans;
int main()
{
	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++)
		ans += s1[i] & s2[i];
	cout << ans << '\n';
	ans.clear();
	
	for (int i = 0; i < s1.size(); i++)
		ans += s1[i] | s2[i];
	cout << ans << '\n';
	ans.clear();

	for (int i = 0; i < s1.size(); i++)
		ans += s1[i] != s2[i] ? '1' : '0';
	cout << ans << '\n';
	ans.clear();

	for (int i = 0; i < s1.size(); i++)
		ans += s1[i] == '1' ? '0' : '1';
	cout << ans << '\n';
	ans.clear();

	for (int i = 0; i < s1.size(); i++)
		ans += s2[i] == '1' ? '0' : '1';
	cout << ans << '\n';

	return 0;
}