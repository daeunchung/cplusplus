#include <bits/stdc++.h>
#include <vector>
using namespace std;
/*
 3<=N<=8 이라서 모든 N 의 경우의 수 만들기 : O(N*N!)  , 8*8! = 32만 , 시간제한 1초라 브루트포스 가능

 */
int calculate(vector<int> &a)
{
    int sum = 0;
    for (int i = 1; i < a.size(); i++) {
        sum += abs(a[i] - a[i - 1]);
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int ans = -1;
    // 첫순열로 정렬한번 하고 브루트포스 
    do {
        int t = calculate(a);
        if (ans < t) ans = t;
    } while (next_permutation(a.begin(), a.end()));
    
    cout << ans << '\n';
    return 0;
}