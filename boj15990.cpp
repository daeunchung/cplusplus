/*
dp �޸������̼� �ÿ� �ʿ��� ������ 2���� �迭�� 2���� �迭�� �Ǵ� �� 
D[i][j] = i�� 1,2,3�� ������ ��Ÿ���� ����� ��, �������� ����� ���� j

D[i][1] = i�� 1,2,3�� ������ ��Ÿ���� ����� ��, �������� ����� ���� 1 => �ٷ����� ��밡���� �� 2,3
D[i][2] = i�� 1,2,3�� ������ ��Ÿ���� ����� ��, �������� ����� ���� 2 => �ٷ����� ��밡���� �� 1,3
D[i][3] = i�� 1,2,3�� ������ ��Ÿ���� ����� ��, �������� ����� ���� 3 => �ٷ����� ��밡���� �� 1,2

D[i][1] = D[i-1][2] + D[i-1][3] (i>1), D[1][1] = 1, D[i][1] = 0 (i<1)
D[i][2] = D[i-2][1] + D[i-2][3] (i>2), D[2][2] = 1, D[i][2] = 0 (i<2)
D[i][3] = D[i-3][1] + D[i-3][2] (i>3), D[3][3] = 1, D[i][3] = 0 (i<3)

�ƹ� �������� D[0][1] = D[0][2] = D[0][3] = 1 �� �ʱ�ȭ�ϸ� �ߺ� �߻��ϱ⿡
��ó�� ���� ó���� ���־�� ��
*/

#include <iostream>
using namespace std;
long long D[100001][4];	// ���� 0���� �ʱ�ȭ
const long long mod = 1000000009LL;
const int limit = 100000;
void run(long long (*d)[4])
{
    for (int i = 1; i <= limit; i++) {
        if (i >= 1) {
            d[i][1] = d[i - 1][2] + d[i - 1][3];
            if (i == 1) {
                d[i][1] = 1;
            }
        }
        if (i - 2 >= 0) {
            d[i][2] = d[i - 2][1] + d[i - 2][3];
            if (i == 2) {
                d[i][2] = 1;
            }
        }
        if (i - 3 >= 0) {
            d[i][3] = d[i - 3][1] + d[i - 3][2];
            if (i == 3) {
                d[i][3] = 1;
            }
        }
        d[i][1] %= mod;
        d[i][2] %= mod;
        d[i][3] %= mod;
    }
}
int main()
{
	run(D);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
        cout << (D[n][1] + D[n][2] + D[n][3]) % mod << '\n';
	}
	return 0;
}