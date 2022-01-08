/* nCm = n!/((n-m)!m!) ���� 0�� ����
factorial�� 2�ǰ��� > 5�ǰ��� �׻� �����Ͽ� �� ���� ������ 5�� ������ ���������
������ ��� ���� �𸣱⿡, 2�� ����, 5�� ������ ���ÿ� ������� �Ѵ�.
*/
// 5C2 = 5*4 /2*1 = 5!/3!2!
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    long long two = 0, five = 0;
    long long n, m;
    cin >> n >> m;
    for (long long i = 2; i <= n; i *= 2) {
        two += n / i;
    }
    for (long long i = 2; i <= n - m; i *= 2) {
        two -= (n - m) / i;
    }
    for (long long i = 2; i <= m; i *= 2) {
        two -= m / i;
    }
    for (long long i = 5; i <= n; i *= 5) {
        five += n / i;
    }
    for (long long i = 5; i <= n - m; i *= 5) {
        five -= (n - m) / i;
    }
    for (long long i = 5; i <= m; i *= 5) {
        five -= m / i;
    }
    cout << min(two, five) << '\n';
    return 0;
}