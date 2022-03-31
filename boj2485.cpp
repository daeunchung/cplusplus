// ��Ŭ���� ȣ����  3 �� N �� 100,000,  ���μ��� ��ġ�� ��Ÿ���� ������ 1,000,000,000 ���� ���� ����
// treegap �� �ִ����� ���ϱ�
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
long long t[1000001];
long long ans;
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	cin >> t[0] >> t[1];
	ans = t[1] - t[0];
	for (int i = 2; i < n; i++)
	{
		cin >> t[i];
		ans = gcd(ans, t[i] - t[i - 1]);
	}

	cout << (t[n - 1] - t[0]) / ans - n + 1 << '\n';
	return 0;
}