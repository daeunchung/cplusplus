/* 1233. [S/W 문제해결 기본] 9일차 - 사칙연산 유효성 검사 D4 */
#include <iostream>
using namespace std;
int testCase = 10, N, answer, ll, rr, num;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= testCase; i++)
	{
		answer = 1;
		cin >> N;	// node 수
		for (int i = 1; i <= N; i++) {
			char op;
			cin >> i >> op;

			if (i <= N / 2)
			{
				if (i == N / 2 && N % 2 == 0) cin >> ll;
				else cin >> ll >> rr;

				if (op >= '0' && op <= '9') answer = 0;
			}
			else
			{
				if (!(op >= '0' && op <= '9')) answer = 0;
			}
		}

		cout << "#" << i << " " << answer << "\n";
	}
	return 0;
}