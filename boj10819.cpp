#include <bits/stdc++.h>
#include <vector>
using namespace std;
/*
 3<=N<=8 �̶� ��� N �� ����� �� ����� : O(N*N!)  , 8*8! = 32�� , �ð����� 1�ʶ� ���Ʈ���� ����

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
    // ù������ �����ѹ� �ϰ� ���Ʈ���� 
    do {
        int t = calculate(a);
        if (ans < t) ans = t;
    } while (next_permutation(a.begin(), a.end()));
    
    cout << ans << '\n';
    return 0;
}