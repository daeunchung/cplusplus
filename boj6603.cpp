/*
1. ���� ����
�� ���� 1, �Ȱ����� 0 => ���� 6��, �Ȱ��� k-6��
0�� k-6��, 1�� 6�� ���� ���� next_permu �ص� �ȴ�
8���� �� : 1 2 3 5 8 13 21 34 �� 11111100 �̸� 1 2 3 5 8 13 ��

2. ���
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// ������ 0, ���� ���� ���� 1 �� ���������Ͽ���
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	int n;
	while (cin >> n && n != 0)
	{
		vector<int> v(n);
		for(int i=0; i<n; i++)
			cin >> v[i];	// �Է½� ��������

		vector<int> idx(n);
		for (int i = 0; i < 6; i++) 
			idx[i] = 0;
		for (int i = 6; i < n; i++) 
			idx[i] = 1;

		do {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (idx[i] == 0) {
					cnt++;
					cout << v[i];
					if (cnt == 6) {
						cout << '\n';
						break;
					}
					cout << ' ';
				}
			}
		} while (next_permutation(idx.begin(), idx.end()));
		cout << '\n';
	}
	return 0;
}