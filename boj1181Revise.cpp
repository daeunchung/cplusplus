#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	else
		return a.size() < b.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> a[i];
	}
	sort(a.begin(), a.end(), compare);

	string tmp;
	for (int i = 0; i < n; i++) {
		// 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다
		if (tmp == a[i]) continue;
		cout << a[i] << '\n';
		tmp = a[i];	
	}
	return 0;
}
