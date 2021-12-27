/* 1245. [S/W 문제해결 응용] 2일차 - 균형점 D5 */
#include <iostream>
using namespace std;
int testCase, N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(10);

	double pos[10] = { 0, };
	double mass[10] = { 0, };

	cin >> testCase;
	for (int idx = 1; idx <= testCase; idx++)
	{
		double ans[9] = { 0, };
		cin >> N;
		for (int i = 0; i < N; i++) cin >> pos[i];
		for (int i = 0; i < N; i++) cin >> mass[i];
		cout << "#" << idx << " ";

		// 이진탐색
		// N개의 자성점을 입력받아서 N-1 개의 균형점을 출력해야하므로
		for (int i = 1; i < N; i++)
		{
			double sum = 0;
			double left = pos[i - 1];
			double right = pos[i];
			double mid = (left + right) / 2;
			int count = 1;
			while (1)
			{
				mid = (left + right) / 2;
				sum = 0;
				// m1 은 균형점의 질량으로 모두 동일하기 때문에 m2 인 각 자성점의 질량만 고려하면 된다.
				for (int j = 0; j < i; j++) {
					sum += (mass[j]) / ((mid - pos[j]) * (mid - pos[j]));
				}
				for (int j = i; j < N; j++) {
					sum -= (mass[j]) / ((pos[j] - mid) * (pos[j] - mid));
				}
				if (sum == 0) break;

				if (sum > 0) left = mid;
				else {
					right = mid;
					sum = sum * (-1);
				}
				
				if (++count > 50) break;	// 횟수 제한 주지 않으면 시간 초과 발생
			}
			cout << mid << " ";
		}
		cout << "\n";
	}
	return 0;
}