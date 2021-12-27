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
	cin.ignore();	// testcase'\n' ������ ���๮�ڸ� �����ϰ� ���ش�.
	while (t--)
	{
		string str;
		getline(cin, str);	// ������ �Է� �������� ���๮�� ���������� ���پ� �Է¹޾Ƽ� str �� �־��ش�
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