/*
D[i][0] i������ ��ƼĿ�� ���� ���� ��� ���� �ִ�
D[i][j] i������ j��° ��ƼĿ�� ���� ��� ���� �ִ�
�ֹ��� : D[i][j] = 2*i ���� ���� �� �ִ� �ִ�����, i�� ������ ��� ��ƼĿ�� j
*/
#include <iostream>
#include <algorithm>
using namespace std;
int p[100001][2];	// sticker points
int d[100001][3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> p[j][i];

		d[0][0] = d[0][1] = d[0][2] = 0;
		for (int i = 1; i <= n; i++) {
			d[i][0] = max({ d[i - 1][0], d[i - 1][1], d[i-1][2] });
			d[i][1] = max(d[i - 1][2], d[i - 1][0]) + p[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + p[i][1];
		}
		cout << max({ d[n][0], d[n][1], d[n][2] }) << '\n';
	}
	return 0;
}