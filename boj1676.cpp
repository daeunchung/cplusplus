/* ������ N! �� ���� ���ϱ�� ����� C++�� �ڷ��� ū�� ����ϰ�, Java�� BigInteger ���, Python�� ���ڱ��� ������������ ������ ���ϱ�� �Ұ���
���ڰ� �ſ� ��� ������ �ð����⵵�� O(1)�̶�� �� �� ����. �׳� �������� 2*5 ���� ������ ã�°� �ذ��� */

#include <iostream>
using namespace std;
int n, ans;
int main()
{
	cin >> n;
	int d = 5;
	while (d <= n)
	{
		ans += n / d;
		d *= 5;
	}
	cout << ans << '\n';
	return 0;
}