#include <iostream>
#include <string>
using namespace std;
int num[10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, c;
	cin >> a >> b >> c;
	int m = a * b * c;
	string ans = to_string(m);
	for (int i = 0; i < ans.size(); i++) num[ans[i]-'0']++;
	for (int i = 0; i < 10; i++) cout << num[i] << '\n';
	return 0;
}
