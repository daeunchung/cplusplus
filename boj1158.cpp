// 21-12-25
// ó������ ��� ����Ǫ�� ������ ť�� Ǯ�� ? �ؼ� vector �� �Ϸ��� ������
// ť�� ����϶�� ������ �������̱⿡ ������ �����غ��� ť�� ����� �� �־���.
// �ؼ����� ���ش��� ť ���� �� �ʿ� ���� �������..
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;

	queue<int> q;
	for (int i = 1; i <= n; i++) q.push(i);

	cout << '<';
	int check = 0, cnt = 0;
	while (cnt < n) {
		int tmp = q.front();
		q.pop();
		check++;
		if (check % k == 0) {
			cout << tmp;
			if (cnt != n - 1) cout << ", ";
			cnt++;
		}
		else if (check % k != 0) {
			q.push(tmp);
		}
	}
	cout << '>';
	return 0;
}