/* LIS Longest Increasing Subsequence
D[i] = A[1], ... A[i] ���� ������ ���� ��, A[i]�� ���������� �ϴ� ���� �� �����ϴ� �κ� ������ ����
D[i] = max(D[j]) + 1 (j < i, A[j] < A[i])
���� Ǭ ������� �ٸ��� n = 6�϶� D[6] �� ���� �ƴ� �����ִ�. ��ü D[i]�� �� �߿� �ִ밪�� ������ �ȴ�
=> O(N����)
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> d(n, 1);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[j] < a[i] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
	cout << *max_element(d.begin(), d.end()) << '\n';
	return 0;
}
