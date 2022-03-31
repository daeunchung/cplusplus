/*
https://blog.encrypted.gg/945
��� ���� ���� ���� ���� ���� ������ ��ü ��
������ ���Ұ� n���̸� ���°���Ʈ���� �������� 2^n ��

�Ʒ� ������ ����ĥ ����
�� ���´� �� ������ �б��ϴµ� ������ ���� ���� ���� ������ �߰����� ���� ����̰� �������� ������ �߰��� ��� 

e.g.) ���� -2, 5, 3
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
    // Ʈ���� �簥�� �б�
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
    if (s == 0) cnt--;  // �������� ������ ���� 0
    cout << cnt;
}
