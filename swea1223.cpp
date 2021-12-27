/* 1223. [S/W �����ذ� �⺻] 6���� - ����2 D4 */
// ���� -> ����ǥ�� : �����ڸ� stack��
// ����ǥ��� ��� : �ǿ����ڸ� stack��
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int testCase = 10, answer, slen, a, b;
		string str;		// ���� ǥ���
		string str1;	// ���� ǥ���
		stack<char> s;	// ���� -> ���� ����� stack
		stack<int> s1;	// ���� ǥ��� ���� stack

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int Tc = 1; Tc <= testCase; Tc++)
	{
		cin >> slen >> str;
		str1 = "";
		
		// ���� -> ���� ǥ���
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
			else // �����̸�
			{
				str1 += str[i];
			}
		}
		// �����ִ� ������ ó��
		while (!s.empty()) {
			str1 += s.top();
			s.pop();
		}

		// ���� ǥ��� ���
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
