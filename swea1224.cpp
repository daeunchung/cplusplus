/* 1224. [S/W 문제해결 기본] 6일차 - 계산기3 D4 */
// 중위 -> 후위표기 : 연산자를 stack에
// stack의 top 이 자신보다 순위가 높거나 같으면, stack의 top 이 자신보다 우선순위가 낮을때 까지 pop() 하고 자신(연산자)을 push()
// 중위에 ) 이면 ( 나올때까지 stack 의 모든 연산자를 pop  
// 
// 후위표기법 계산 : 피연산자를 stack에
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int testCase = 10, answer, length, a, b;
string inorder;		// 중위 표기식
string postorder;	// 후위 표기식

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int Tc = 1; Tc <= testCase; Tc++)
	{
		stack<char> st1;	// 중위 -> 후위 변경용 stack
		cin >> length >> inorder;
		postorder = "";

		// 중위 -> 후위 표기식
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
			else // 숫자이면
			{
				postorder += inorder[i];
			}
		}

		// 남아있는 연산자 처리
		while (!st1.empty()) {
			postorder += st1.top();
			st1.pop();
		}

		stack<int> st2;	// 후위 계산용 stack
		// 후위 표기식 계산
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
