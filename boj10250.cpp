#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int cnt, h, w, n;
	cin >> cnt;
	for (; cnt--;) {
		cin >> h >> w >> n;
		if (n % h == 0) cout << 100 * h + (n / h) << '\n';
		else cout << 100 * (n % h) + (n / h) + 1 << '\n';
	}
	return 0;
}
// 'Ʋ�Ƚ��ϴ�' 7�� ���� ���� ^^ �ᱹ �ذ�
// 'Ʋ�Ƚ��ϴ�' �� ��¥ '��� ����� Ʋ���� ��쿡 ������ ���'�̴� �� ���� �¾�������� Ȯ�ſ� ���� �ǹ� ���� ���� ������ �ٽ� Ǯ���