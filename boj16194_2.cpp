#include <iostream>
#include <vector>
using namespace std;
// d[] : 카드 i개 구매하는 최소 비용
int min(int x, int y)
{
    if (x < y) return x;
    else return y;
}
int main() {

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> d(n + 1, 10000000);
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            d[i] = min(d[i], d[i - j] + a[j]);
        }
    }
    cout << d[n] << '\n';
    return 0;
}