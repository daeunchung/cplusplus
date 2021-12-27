/* 1223. [S/W 문제해결 기본] 6일차 - 계산기2 D4 */
// 중위 -> 후위표기 : 연산자를 stack에
// 후위표기법 계산 : 피연산자를 stack에
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int testCase = 10, answer, slen, a, b;
		string str;		// 중위 표기식
		string str1;	// 후위 표기식
		stack<char> s;	// 중위 -> 후위 변경용 stack
		stack<int> s1;	// 후위 표기식 계산용 stack

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int Tc = 1; Tc <= testCase; Tc++)
	{
		cin >> slen >> str;
		str1 = "";
		
		// 중위 -> 후위 표기식
		for (int i = 0; i < slen; i++)
		{
			if (str[i] == '*')
			{
				while (!s.empty() && s.top() == '*') {
					str1 += s.top();
					s.pop();
				}
				s.push(str[i]);
			}
			else if (str[i] == '+')
			{
				while (!s.empty() && (s.top() == '*' || s.top() == '+')) {
					str1 += s.top();
					s.pop();
				}
				s.push(str[i]);
			}
			else // 숫자이면
			{
				str1 += str[i];
			}
		}
		// 남아있는 연산자 처리
		while (!s.empty()) {
			str1 += s.top();
			s.pop();
		}

		// 후위 표기식 계산
		for (int i = 0; i < str1.length(); i++)
		{
			if (str1[i] == '+')
			{
				b = s1.top();	s1.pop();
				a = s1.top();	s1.pop();
				s1.push(a + b);
			}
			else if (str1[i] == '*')
			{
				b = s1.top();	s1.pop();
				a = s1.top();	s1.pop();
				s1.push(a * b);
			}
			else
				s1.push(str1[i] - '0');
		}

		cout << "#" << Tc << " " << s1.top() << "\n";
	}
	return 0;
}
