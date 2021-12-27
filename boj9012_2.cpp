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
				break;	// 강사님은 valid 함수를 만들어서 여기서 break 말고 return "NO"; 로 함수 끝내고 나오도록 했음
			}
		}
		if (count == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}