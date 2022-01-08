/* D[i] = 3*i �� ä��� ����� ��
�ֹ��ش��� ���� �ٶ����� ���� �ƴ϶�� �Ͻ� (�߰��Ǵ� Ÿ�ϸ��� ������ ��찡 �� ������ �� �ִµ� �̸� ã�Ƴ����Ѵ�)
D[i] = 3 * D[i-2] + 2 * D[i-4] + 2 * D[i-6] + ...

�ǹ� : N�� Ȧ���� ���� �� �� ���°ǰ�?
*/
#include <iostream>
using namespace std;
long long d[31];
int main()
{
	int n;	cin >> n;
	d[0] = 1;	// d[2] = 3;
	for (int i = 2; i <= n; i += 2) {
		d[i] += 3 * d[i - 2];
		for (int j = i - 4; j >= 0; j -= 2) {
			d[i] += 2 * d[j];
		}
	}
	cout << d[n] << '\n';
	return 0;
}