#include <iostream>
#include <string>
#include <stack>
using namespace std;
// 마지막 입력된 괄호를 저장하려고 하지말고 bool flag 를 활용하도록
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1)
	{
		string str;
		stack<char> s;
		bool flag = true;
		getline(cin, str);
		if (str == ".") break;

		for (char ch : str)
		{
			if (ch == '(' || ch == '[') s.push(ch);
			else if (ch == ')') 
			{
				if (s.empty() || s.top() != '(') {
					flag = false;	break;
				}
				s.pop();
			}
			else if (ch == ']') 
			{
				if (s.empty() || s.top() != '[') {
					flag = false;	break;
				}
				s.pop();
			}
			else if (ch == '.')
				if (!s.empty()) flag = false;
		}

		if (flag) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
	return 0;
}