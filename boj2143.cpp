//// 이분탐색 + 누적 합
//// https://codecollector.tistory.com/1054
//// 생각지도 못했으며 다른사람 코드 봐도 간신히 이해했음 
//
//#include <bits/stdc++.h>
//#define ll long long
//using namespace std;
//ll n, m, t, ans;
//int main() {
//    cin >> t >> n;
//    vector <ll> a(n);
//    for (int i = 0; i < n; i++) cin >> a[i];
//    cin >> m;
//    vector <ll> b(m);
//    for (int i = 0; i < m; i++) cin >> b[i];
//    for (int i = 0; i < n; i++) {
//        ll sum = a[i];
//        for (int j = i + 1; j < n; j++) {
//            sum += a[j];
//            a.push_back(sum);
//        }
//    }
//
//    for (int i = 0; i < m; i++) {
//        ll sum = b[i];
//        for (int j = i + 1; j < m; j++) {
//            sum += b[j];
//            b.push_back(sum);
//        }
//    }
//    sort(b.begin(), b.end());
//    for (int i = 0; i < a.size(); i++) {
//        int idx = lower_bound(b.begin(), b.end(), t - a[i]) - b.begin();
//        int endIdx = upper_bound(b.begin(), b.end(), t - a[i]) - b.begin();
//        ans += endIdx - idx;
//    }
//    cout << ans << '\n';
//}