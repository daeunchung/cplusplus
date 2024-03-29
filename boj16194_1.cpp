#include <iostream>
#include <vector>
using namespace std;
 //d[] : 카드 i개 구매하는 최소 비용

int main() {

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> d(n + 1, -1);
    d[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if(d[i] == -1 || d[i] > d[i - j] + a[j])
            d[i] = d[i - j] + a[j];
        }
    }
    cout << d[n] << '\n';
    return 0;
}