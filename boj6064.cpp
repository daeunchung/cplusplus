// ī�� �޷� : �ǳ� �ٸ� �غ��� . ��¥ ��� ��츦 �� ����غ� �ʿ䰡 ���� ��� �߰� �߰� ��ŵ�ϸ� �����ϴ� ���
// 1<=M,N <=40,000 �̶� MN ���� �˻��ϸ� 16�� O(N����) => 16�� (�ð��ʰ�)
// ���� x,y �� x ���� ��ġ�Ҷ��� ã�ư��鼭 N�� üũ�ϸ� �ȴ� => O(N)
// <���� Ǯ�� > ������ ������ ����ϱ� ���Ͽ� x, y���� x-1, y-1 �� �̸� 1�� ���ش�. �ð� save 
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	int tc, m, n, x, y;	
	cin >> tc;
	while (tc--)
	{
		int ans = 0;
		bool exists = false;

		cin >> m >> n >> x >> y;
		for (int i = x; i <= m*n; i += m)
		{
			if (i % n == y % n) {
				ans = i;
				exists = true;
				break;
			}
		}
		if (!exists) 
			ans = -1;
		cout << ans << '\n';
	}
	return 0;
}