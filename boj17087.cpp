#include <iostream>
#include <vector>
using namespace std;
int gcd(int x, int y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}
int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int diff = x - s;
        if (diff < 0) diff = -diff;
        a[i] = diff;
    }
    int ans = a[0];
    for (int i = 1; i < n; i++) {
        ans = gcd(ans, a[i]);
    }
    cout << ans << '\n';
    return 0;
}