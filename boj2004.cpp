/* nCm = n!/((n-m)!m!) 조합 0의 개수
factorial은 2의개수 > 5의개수 항상 성립하여 더 적은 개수인 5의 개수만 세면되지만
조합은 어떻게 될지 모르기에, 2의 개수, 5의 개수를 동시에 세어줘야 한다.
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