/*
https://blog.encrypted.gg/945
노드 안의 값은 현재 내가 택한 수열의 전체 합
수열의 원소가 n개이면 상태공간트리의 리프노드는 2^n 개

아래 레벨로 가지칠 때에
각 상태는 두 갈래로 분기하는데 왼쪽은 현재 보는 수를 수열에 추가하지 않은 경우이고 오른쪽은 수열에 추가한 경우 

e.g.) 수열 -2, 5, 3
           0
    0           -2
 0     5     -2     3
0 3   5 8   -2 1   3 6 
*/
#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[21];
int cnt = 0;
void func(int cur, int tot)
{
    if (cur == n) {
        if (tot == s) cnt++;
        return;
    }
    // 트리의 양갈래 분기
    func(cur + 1, tot);
    func(cur + 1, tot + arr[cur]);
}
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(nullptr);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    func(0, 0);
    if (s == 0) cnt--;  // 공집합은 원소의 합이 0
    cout << cnt;
}
