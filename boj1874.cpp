// 21-12-21 ���ü��� �������
#include <iostream>
#include <string>
#include <stack>
using namespace std;
/* 
* 1 2 3 ... n ������� push�Ѵ� 
=> ���� ��ǲ���� �������� ��������, ��¥�� 1�� �����ϴ� ���´ϱ� "���� �����Ѵ�, �������Ѵ�" ���� ������ ����

pop �Ҷ����� ������ �ϳ��� ���� �����ش�
* input m : 1 2 3 4 5 6 7 8 (������ ������ ���� ������������ ��ǲ���� �������� ������ ����) 
���ʴ�� x : 4 3 6 8 7 5 2 1 
������ �� a[i]�� ����������� stack ���� 1~a[i]�� ��� push�� �Ǿ��ִ� ���¿��� �Ѵ�
������ �� x�� stack�� top���� ������ x�� �̹� ���ÿ� ���ִµ� �ٷ� �� �� ���� ������ ���� �Ұ���
������ �� x�� stack�� top���� ũ�� x������ �� (x���� ���� ����)���� push�ϰ� 
*/

string ans = "";
int n, x, m = 0;
bool f = true;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<int> s;
	cin >> n;

	while (n--) {
		cin >> x;
		if (x > m)
		{
			while (x > m) {
				s.push(++m); ans += "+";
			}
			s.pop(); ans += "-";
		}
		else // �̹� x�� ���ÿ� ���ִ�
		{
			if (!s.empty())
			{
				if (x == s.top()) {
					s.pop(); ans += "-";
					//continue;
				}
				else {
					f = false;
					cout << "NO" << '\n';
					return 0;
				}
			}
		}
	}
	if (f) {
		for (char ch : ans)
			cout << ch << '\n';
	}
	return 0;
}