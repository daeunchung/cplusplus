// Ǯ�� 1 ��Ʈ����ũ  https://regularmember.tistory.com/90
// ���η� �ڸ� ���0, ���η� �ڸ� ���1 :: 2�������̶� ��Ʈ����ŷ ����
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int arr[5][5];
int N, M;	char ch;
//2 3
//123
//312
//=> 123312 �� ����
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ch;
			arr[i][j] = ch - '0';
		}
	}
 	
	int ans = 0;
	for (int b = 0; b < (1 << (N * M)); b++) {
		int sum = 0;
		
		// ���� 0
		for (int i = 0; i < N; i++) {
			int tmp = 0;
			for (int j = 0; j < M; j++) {
				// ���ٷ� �̾�ٿ��� �� �ε���
				int k = i * M + j;
				// k��° �ڸ����� 0 (����)
				if ((b & (1 << k)) == 0) {
					tmp = tmp * 10 + arr[i][j];
				}
				else {	// ���γ�, ���ν��� (�տ����� ������� ������ sum�� ����)
					sum += tmp;
					tmp = 0;
				}
			}
			// �� �� ����
			sum += tmp;
		}

		// ���� 1
		for (int j = 0; j < M; j++) {
			int tmp = 0;
			for (int i = 0; i < N; i++) {
				// ���ٷ� �̾�ٿ��� �� �ε���
				int k = i * M + j;
				// k��° �ڸ����� 1 (����)
				if ((b & (1 << k)) != 0) {
					tmp = tmp * 10 + arr[i][j];
				}
				else {	// ���γ�, ���ν��� (�տ����� ������� ������ sum�� ����)
					sum += tmp;
					tmp = 0;
				}
			}
			// �� �� ����
			sum += tmp;
		}

		// for(int b...)���� sum �� �߿� �ִ� ����
		if (ans < sum) ans = sum;
	}

	cout << ans << '\n';
	return 0;
}
