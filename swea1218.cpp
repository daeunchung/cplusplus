/* 1218. [S/W ¹®Á¦ÇØ°á ±âº»] 4ÀÏÂ÷ - °ýÈ£ Â¦Áþ±â D4 */
#include <iostream>
#include <stack>
using namespace std;
int testCase = 10, answer, N;
char ch;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int Tc = 1; Tc <= testCase; Tc++)
	{
		cin >> N;
		stack<char> s;
		for (int i = 0; i < N; i++)
		{
			cin >> ch;
			if (ch == '}' && s.top() == '{') s.pop();
			else if (ch == ']' && s.top() == '[') s.pop();
			else if (ch == ')' && s.top() == '(') s.pop();
			else if (ch == '>' && s.top() == '<') s.pop();
			else s.push(ch);
		}
		if (s.empty()) answer = 1;
		else answer = 0;
		cout << "#" << Tc << " " << answer << "\n";
	}
	return 0;
}