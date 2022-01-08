/* ���� �� �����ϴ� �κ� ���� LIS Longest Increasing Subsequence 
* D[i] = i��°���� ������ LIS�� ���� (�������� ~ A[j], A[i] �϶� ������ ����)
* D[i] = max(D[j] + 1), j<i, A[j]<A[i] , D[1] = 1
* 
* 11055 �� ���� ū �����ϴ� �κ� ���� : ���� ������ ���� �ִ��̾�� �Ѵ� 
* D[i] = max(D[j] + A[i]), j<i, A[j]<A[i] , D[1] = A[1]
*/
#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int d[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) {
		d[i] = a[i];
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + a[i] )
				d[i] = d[j] + a[i];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < d[i]) ans = d[i];
	}
	cout << ans << '\n';
	return 0;
}