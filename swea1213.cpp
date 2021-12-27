/* 1213. [S/W 문제해결 기본] 3일차 - String D3 */
#include <iostream>
#include <string>
using namespace std;
int arr[100][100];
int testCase = 10, answer;
string pattern, str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int Tc = 1; Tc <= testCase; Tc++)
	{
		cin >> Tc >> pattern >> str;
		answer = 0;
		int sl = str.length(), pl = pattern.length();
		for (int i = 0; i < sl - pl + 1; i++)
		{
			string tmp = "";
			for (int j = i; j < i + pl; j++)
				tmp += str[j];
			if (tmp == pattern) answer++;
		}
		cout << "#" << Tc << " " << answer << endl;
	}
	return 0;
}
