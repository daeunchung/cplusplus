/* 1224. [S/W �����ذ� �⺻] 6���� - ����3 D4 */
// ���� -> ����ǥ�� : �����ڸ� stack��
// stack�� top �� �ڽź��� ������ ���ų� ������, stack�� top �� �ڽź��� �켱������ ������ ���� pop() �ϰ� �ڽ�(������)�� push()
// ������ ) �̸� ( ���ö����� stack �� ��� �����ڸ� pop  
// 
// ����ǥ��� ��� : �ǿ����ڸ� stack��
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int testCase = 10, answer, length, a, b;
string inorder;		// ���� ǥ���
string postorder;	// ���� ǥ���

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int Tc = 1; Tc <= testCase; Tc++)
	{
		stack<char> st1;	// ���� -> ���� ����� stack
		cin >> length >> inorder;
		postorder = "";

		// ���� -> ���� ǥ���
		for (int i = 0; i < length; i++)
		{
			if (inorder[i] == '*')
			{
				while (!st1.empty() && st1.top() == '*') {
					postorder += st1.top();
					st1.pop();
				}
				st1.push(inorder[i]);
			}
			else if (inorder[i] == '+')
			{
				while (!st1.empty() && (st1.top() == '*' || st1.top() == '+')) {
					postorder += st1.top();
					st1.pop();
				}
				st1.push(inorder[i]);
			}
			else if (inorder[i] == '(')
			{
				st1.push(inorder[i]);
			}
			else if (inorder[i] == ')')
			{
				while (!st1.empty() && (st1.top() != '(')) {
					postorder += st1.top();
					st1.pop();
				}
				if (!st1.empty() && (st1.top() == '('))
					st1.pop();
			}
			else // �����̸�
			{
				postorder += inorder[i];
			}
		}

		// �����ִ� ������ ó��
		while (!st1.empty()) {
			postorder += st1.top();
			st1.pop();
		}

		stack<int> st2;	// ���� ���� stack
		// ���� ǥ��� ���
		for (int i = 0; i < postorder.length(); i++)
		{
			if (postorder[i] == '+')
			{
				b = st2.top();	st2.pop();
				a = st2.top();	st2.pop();
				st2.push(a + b);
			}
			else if (postorder[i] == '*')
			{
				b = st2.top();	st2.pop();
				a = st2.top();	st2.pop();
				st2.push(a * b);
			}
			else
				st2.push(postorder[i] - '0');
		}

		cout << "#" << Tc << " " << st2.top() << "\n";
	}
	return 0;
}
