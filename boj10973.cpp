#include <iostream>
#include <vector>
using namespace std;
bool prev_permutation(vector<int>& a, int n)
{
    int i = n - 1;
    while (i > 0 && a[i - 1] <= a[i]) {
        i -= 1;
    }
    if (i <= 0) {   // 가장 첫 순열이다. 이전순열X
        return false;
    }
    int j = n - 1;
    while (a[j] >= a[i - 1]) {
        j -= 1;
    }
    swap(a[i - 1], a[j]);
    j = n - 1;
    while (i < j) {
        swap(a[i], a[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (prev_permutation(a, n)) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
    }
    else {
        cout << "-1";
    }
    cout << '\n';
    return 0;
}