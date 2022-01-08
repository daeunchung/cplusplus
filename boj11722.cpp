/* ���� �� �����ϴ� �κ� ���� LIS Longest Increasing Subsequence
* D[i] = i��°���� ������ LIS�� ���� (�������� ~ A[j], A[i] �϶� ������ ����)
* D[i] = max(D[j] + 1), j<i, A[j]<A[i] , D[1] = 1
*
* 11055 �� ���� ū �����ϴ� �κ� ���� : ���� ������ ���� �ִ��̾�� �Ѵ�
* D[i] = max(D[j] + A[i]), j<i, A[j]<A[i] , D[1] = A[1]
* 
*   vector<int> d(n);
    for (int i=0; i<n; i++) {
        d[i] = a[i];
        for (int j=0; j<i; j++) {
            if (a[j] < a[i] && d[j]+a[i] > d[i]) {
                d[i] = d[j]+a[i];
            }
        }
    }
* 
* 
* 11722 ���� �� �����ϴ� �κ� ���� (2���� Ǯ��)
* D[i] = A[i] ���� �����ϴ� ���� �� �����ϴ� �κ� ������ ����
* D[i] = max(D[j]) + 1  (i<j && A[i] > A[j])
*                  
*   for (int i=n; i>=1; i--) {
        d[i] = 1;
        for (int j=i+1; j<=n; j++) {
            if (a[i] > a[j] && d[i] < d[j]+1) {
                d[i] = d[j]+1;
            }
        }
    }
    int ans = d[1];
    for (int i=2; i<=n; i++) {
        if (ans < d[i]) {
            ans = d[i];
        }
    }
* 
*                    ��  �� 
* 
* D[i] = A[i] ���� ������ ���� �� �����ϴ� �κ� ������ ����
* D[i] = max(D[j]) + 1  (j<i && A[j] > A[i])
* 
*   for (int i=1; i<=n; i++) {
        d[i] = 1;
        for (int j=1; j<=i; j++) {
            if (a[j] > a[i] && d[i] < d[j]+1) {
                d[i] = d[j]+1;
            }
        }
    }
    int ans = d[1];
    for (int i=2; i<=n; i++) {
        if (ans < d[i]) {
            ans = d[i];
        }
    }
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

    // D[i] = A[i] ���� ������ ���� �� �����ϴ� �κ� ������ ����
    for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] > a[i] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < d[i]) ans = d[i];
	}
	cout << ans << '\n';
	return 0;
}