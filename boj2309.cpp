// ���Ʈ���� 9C7 = 9C2 = 36 ����� �ص� ������ ��� ����� ��
#include <iostream>
#include <algorithm>
using namespace std;
int a[9], sum = 0, n = 9;
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sum - a[i] - a[j] == 100) {
				for (int k = 0; k < n; k++)
				{
					if (i == k || j == k) continue;
					cout << a[k] << '\n';
				}
				return 0;
			}
		}
	}
}