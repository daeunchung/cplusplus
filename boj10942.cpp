#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N, M, s, e;			// 1 �� N �� 2,000, ������ ���� M (1 �� M �� 1,000,000), 0.5�� TLg
char ch;	 string str; 	
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> N;
	while (N--) {
		cin >> ch;
		str += ch;
	}
	cin >> M;
	while (M--)
	{
		bool flag = true;
		cin >> s >> e;
		s--; e--;
		while (s != e) {
			if (str[s] != str[e]) {
				flag = false;
				break;
			}
			s++;	e--;
		}
		cout << flag << '\n';
	}
	return 0;
}
// �� Ʋ�Ƚ��ϴ� �ߴ��� �𸣰���
// ���ʿ� DP�̾�� �ؼ� �ð��ʰ��� ������ �´°� ������ 