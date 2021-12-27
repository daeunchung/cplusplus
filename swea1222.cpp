/* 1222. [S/W 문제해결 기본] 6일차 - 계산기1 D4 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;
string str;
int testCase = 10, answer, slen, a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int Tc = 1; Tc <= testCase; Tc++)
	{
		cin >> slen >> str;

		// 중위 -> 후위 표기식
		str.erase(1, 1);
		str += "+";

		stack<int> s;
		for (int i = 0; i < slen; i++)
		{
			if (str[i] == '+')
			{
				b = s.top();	s.pop();
				a = s.top();	s.pop();
				s.push(a + b);
			}
			else
			{
				s.push(str[i] - 48); // 아스키 문자'0' 10진수 48
			}
		}
		cout << "#" << Tc << " " << s.top() << "\n";
		s.pop();
	}
	return 0;
}
