#include<iostream>
#include<string>
#include<algorithm>
#include<set>

using namespace std;
//  set �� ���� ������ �ٲٱ� ���� ����ü Compare ����
struct compare {
	bool operator() (const string& a, const string& b) const {
		if (a.size() == b.size())
			return a < b;
		else
			return a.size() < b.size();
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	set<string, compare> s;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		s.insert(str);
	}

	//for (set<string, compare>::iterator it = s.begin(); it != s.end(); it++)
	//	cout << *it << endl;
	//for(auto it = s.begin(); it != s.end(); it++)
	//	cout << *it << endl;
	for (auto str : s)
		cout << str << '\n';

	return 0;
}