/* ��� �ߺ��� �߻��Ҷ��� ����� �͵鳢�� �׷��� ������ ����ϸ� �ð� save ���� (���� : �������հ��ĸ� �Ƚ�� ������ ����)

�� Ǯ��
���� �ڸ� ���� = n �� = n - (1-1)
���� �ڸ� ���� = n - 9 �� = n - (10-1)
���� �ڸ� ���� n - 99 - n - (100-1)
n �� �ڸ����� k �϶�
k * n - (10^(k-1) + 10^(k-2) + ... + 10^1 + 10^0) + k

�� = k*(n+1) - 1*(10^k - 1)/(10 - 1)
*/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	// N(1 �� N �� 100,000,000)
	int n;
	long long ans = 0;
	cin >> n;	int tmp = n;
	int k = 0;
	while (tmp) {
		tmp /= 10;
		k++;
	}
	ans = k * (n+1) - (pow(10, k) - 1)/(10 - 1);
	cout << ans << '\n';
	return 0;
}
