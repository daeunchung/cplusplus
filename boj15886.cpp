/* (1,x) �� E �̸� (1,x+1)��  w �̸� (1,x-1)��      2 �� N �� 1000
6
EEWW|EW
5
EEEEW
��� ���� ���϶�� ��������
=> WE �� ������ ���ϸ� �ȴ�
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	int n;	string str;
	cin >> n >> str;
	int cnt = 1;
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i - 1] == 'W' && str[i] == 'E') cnt++;
	}
	cout << cnt << '\n';

	return 0;
}