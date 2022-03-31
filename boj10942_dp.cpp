// s ~ e������ �Ӹ�����̷��� s+1 ~ e-1 ������ �Ӹ�����̾�� �Ѵ�. 
// �� ������ arr[s] == arr[e] && palindrom[s + 1][e - 1] == true�� ǥ���� �� �ִ�.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[2001];
bool p[2001][2001] = { false, };
int n, m, s, e;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	// ���� 1
	for (int i = 1; i <= n; i++) {
		p[i][i] = true;
	}

	// ���� 2
	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i + 1])
			p[i][i + 1] = true;
	}

	//���� 3 �̻�
	for (int i = 2; i < n; i++)
		for (int j = 1; j <= n - i; j++)
			//�� �ڰ� ����, �� �� ���̿� �ִ� ������ �Ӹ������ ���
			if (arr[j] == arr[j + i] && p[j + 1][j + i - 1])
				p[j][j + i] = true;

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		cout << p[s][e] << '\n';
	}
	return 0;
}