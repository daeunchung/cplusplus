// 21-12-24
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;
string str;
char cmd;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<char> left, right;
	cin >> str;
	for (char ch : str) {
		left.push(ch);
	}
	cin >> n;
	while (n--)
	{
		cin >> cmd;
		if (cmd == 'L')
		{
			if (!left.empty())
			{
				int num = left.top();
				left.pop();
				right.push(num);
			}
		}
		else if (cmd == 'D')
		{
			if (!right.empty())
			{
				int num = right.top();
				right.pop();
				left.push(num);
			}
		}
		else if (cmd == 'B')
		{
			if (!left.empty())
				left.pop();
		}
		else if (cmd == 'P')
		{
			char c;
			cin >> c;
			left.push(c);
		}
	}
	while (!left.empty())
	{
		int num = left.top();
		left.pop();
		right.push(num);
	}
	while (!right.empty())
	{
		cout << right.top();
		right.pop();
	}
	return 0;
}