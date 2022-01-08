/*
D[i][j] = ���̰� i�̰� �������� ����� ���� j�� ��� ���� ����
D[i][j] = D[i-1][j-1] + D[i-1][j+1]

D[0][x] = 0, D[1][x] = 1 (x != 0), D[1][0] = 0
*/
#include <iostream>
using namespace std;
const long long mod = 1000000000LL;
long long d[101][11];	// ���� 0���� �ʱ�ȭ
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= 9; i++) d[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            //d[i][j] = 0;
            if (j - 1 >= 0) d[i][j] += d[i - 1][j - 1];
            if (j + 1 <= 9) d[i][j] += d[i - 1][j + 1];
            d[i][j] %= mod;
        }
    }
    cout << (d[n][0] + d[n][1] + d[n][2] + d[n][3] + d[n][4] + d[n][5]
        + d[n][6] + d[n][7] + d[n][8] + d[n][9]) % mod << '\n';
    return 0;
}