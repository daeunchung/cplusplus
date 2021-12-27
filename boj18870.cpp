#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> idx(n);
    vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> idx[i];
        points[i] = idx[i];
    }

    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());

    for (auto& c : points) {
        cout << lower_bound(idx.begin(), idx.end(), c) - idx.begin() << ' ';
    }

    return 0;
}