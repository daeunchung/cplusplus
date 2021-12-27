// 21-12-21
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	cin.ignore();	// testcase'\n' 라인의 개행문자를 무시하게 해준다.
	while (t--)
	{
		string str;
		getline(cin, str);	// 마지막 입력 시점부터 개행문자 만날때까지 한줄씩 입력받아서 str 에 넣어준다
		str += '\n';
		stack<char> s;
		for(char ch : str)
		{
			if (ch != ' ' &&  ch != '\n')
			{
				s.push(ch);
			}
			else
			{
				while (!s.empty())
				{
					cout << s.top();
					s.pop();
				}
				cout << " ";
			}
		}
		cout << '\n';
	}
	return 0;
}