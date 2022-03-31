#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(0);  cout.tie(0);
    int n, k;
    string str;

    cin >> n;
    vector<string> v;
    while (n--) {
        cin >> str;
        v.push_back(str);
    }
    cin >> k;
    while (k--) {
        cin >> str; int l = str.size();
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            if (str == v[i].substr(0, l)) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}