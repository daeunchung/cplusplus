/* 1245. [S/W �����ذ� ����] 2���� - ������ D5 */
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

		// ����Ž��
		// N���� �ڼ����� �Է¹޾Ƽ� N-1 ���� �������� ����ؾ��ϹǷ�
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
				// m1 �� �������� �������� ��� �����ϱ� ������ m2 �� �� �ڼ����� ������ ����ϸ� �ȴ�.
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
				
				if (++count > 50) break;	// Ƚ�� ���� ���� ������ �ð� �ʰ� �߻�
			}
			cout << mid << " ";
		}
		cout << "\n";
	}
	return 0;
}