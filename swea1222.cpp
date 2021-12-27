/* 1222. [S/W �����ذ� �⺻] 6���� - ����1 D4 */
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

		// ���� -> ���� ǥ���
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
				s.push(str[i] - 48); // �ƽ�Ű ����'0' 10���� 48
			}
		}
		cout << "#" << Tc << " " << s.top() << "\n";
		s.pop();
	}
	return 0;
}
