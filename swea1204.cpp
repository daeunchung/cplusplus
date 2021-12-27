/* 1204. [S/W 문제해결 기본] 1일차 - 최빈수 구하기 D2 */
#include <iostream>
#include <string.h>
using namespace std;
int score[101];
int Tc, Tnum, N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Tc;
	for (int i = 0; i < Tc; i++)
	{
		memset(score, 0, sizeof(score));
		cin >> Tnum;
		for (int i = 0; i < 1000; i++)
		{
			cin >> N;
			score[N]++;
		}
		int max = -1, answer = -1;
		for (int i = 0; i < 100; i++)
		{
			if (max <= score[i])
			{
				max = score[i];
				answer = i;
			}
		}
		cout << "#" << Tnum << " " << answer << "\n";
	}
	return 0;
}