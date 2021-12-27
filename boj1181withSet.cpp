#include<iostream>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

struct compare
{
	bool operator()(const string& a, const string& b)
	{
		if (a.size() != b.size())
			return a.size() < b.size();
		return a < b;
	}
};

int main()
{
	int n;
	cin >> n;
	set<string, compare> s;
	string tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		s.insert(tmp);
	}

	for (set<string, compare>::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << endl;
	return 0;
}