#include <iostream>
#include <string>
using namespace std;

string eight[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
string inp, ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);
	cin >> inp;
	int n = inp.size();
	for (int i = 0; i < n; i++) {
		ans += eight[inp[i] - '0'];
	}
	//while (ans[0] != '1') {
	//	ans.erase(ans.begin());
	//}
	int idx = 0;
	while (ans[idx] != '1') {
		idx++;
	}
	ans.erase(0, idx);

	if (inp == "0")
		cout << 0 << '\n';
	else
		cout << ans << '\n';
	return 0;
}