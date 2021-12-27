// 21-12-21 VPS Valid Parenthesis String
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int count = 0;
		string str;
		cin >> str;
		for (char ch : str)
		{
			if (ch == '(')
			{
				count++;
			}
			else if (ch == ')') {
				count--;
			}
			if (count < 0) {
				break;	// ������� valid �Լ��� ���� ���⼭ break ���� return "NO"; �� �Լ� ������ �������� ����
			}
		}
		if (count == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}