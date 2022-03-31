/* (1,x) 가 E 이면 (1,x+1)로  w 이면 (1,x-1)로      2 ≤ N ≤ 1000
6
EEWW|EW
5
EEEEW
덩어리 갯수 구하라는 문제같음
=> WE 의 갯수를 구하면 된다
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