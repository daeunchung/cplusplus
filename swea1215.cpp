/* 1215. [S/W �����ذ� �⺻] 3���� - ȸ��1 D3 */

// ȸ�� palindrome      E.g. �ⷯ�� level
#include <iostream>
#include <string>
using namespace std;
char arr[8][8];
int testCase = 10, answer, plen;
string pattern, str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int Tc = 1; Tc <= testCase; Tc++)
	{
		cin >> plen;	// length of the palindrome
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++) cin >> arr[i][j];

		answer = 0;
		// ����
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j <= 8 - plen; j++)
			{
				int count = 0;
				for (int k = 0; k < plen / 2; k++)
				{
					if (arr[i][j+k] == arr[i][j+plen-1-k]) count++;
				}
				if (count == plen / 2) answer++;
			}
		}

		// ����
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j <= 8 - plen; j++)
			{
				int count = 0;
				for (int k = 0; k < plen / 2; k++)
				{
					if (arr[j+k][i] == arr[j + plen - 1 - k][i]) count++;
				}
				if (count == plen / 2) answer++;
			}
		}
		// ���
		cout << "#" << Tc << " " << answer << "\n";
	}
	return 0;
}