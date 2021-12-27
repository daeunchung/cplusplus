/* 1231. [S/W �����ذ� �⺻] 9���� - ������ȸ D4 */
// ���� ��ȸ L N R
#include <iostream>
using namespace std;
int testCase = 10, N;
char tree[101];

void Inorder(int v)
{
	if (v > N) return;

	Inorder(2 * v);
	cout << tree[v];
	Inorder(2 * v + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= testCase; i++)
	{
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> i >> tree[i];
			
			int left, right;
			if (i < N / 2) {
				cin >> left >> right;
			}
			else if (i == N / 2) {
				cin >> left;
				if (N % 2)	// ��� ���� Ȧ���̸� N/2��° ��尡 ��,�� �ڽ��� ������.
					cin >> right;
			}
		}

		cout << "#" << i << " ";
		Inorder(1);
		cout << "\n";
	}
	return 0;
}