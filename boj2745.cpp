// ���� ��ȯ  (2 �� B �� 36)  B���� �� N�� 10�������� �ٲٸ�, �׻� 10�ﺸ�� �۰ų� ����.
#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	string str;		int B, expo;
	cin >> str >> B;
	ll ans = 0;
	for(int i = str.size()-1; i>=0; i--) {
		char ch = str[str.size() - 1 - i];

		if ('0' <= ch && ch <= '9') expo = ch - '0';
		else expo = ch - 'A' + 10;

		ans += expo * pow(B, i);
	}
	cout << ans << '\n';
	return 0;
}