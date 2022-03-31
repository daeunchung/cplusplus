#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N, M, s, e;			// 1 ≤ N ≤ 2,000, 질문의 개수 M (1 ≤ M ≤ 1,000,000), 0.5초 TLg
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
// 왜 틀렸습니다 뜨는지 모르겠음
// 애초에 DP이어야 해서 시간초과가 떠야지 맞는거 같은데 