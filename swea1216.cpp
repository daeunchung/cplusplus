/* 1216. [S/W �����ذ� �⺻] 3���� - ȸ��2 D3 */

// ȸ�� palindrome      E.g. �ⷯ�� level
#include <iostream>
#include <string>
using namespace std;
char arr[100][100];
int testCase = 10, answer;
bool check;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int Tc = 1; Tc <= testCase; Tc++)
	{
		cin >> Tc;
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++) cin >> arr[i][j];

		answer = -1;
		// ����
		for (int len = 0; len < 100; len++)
		{
			for (int i = 0; i < 100; i++)
			{
				for (int j = 0; j <= 100 - len; j++)
				{
					check = true;
					for (int k = 0; k < len / 2; k++)
					{
						if (arr[i][j + k] != arr[i][j + len - 1 - k]) {
							check = false;
							break;
						}
					}
					if (check && answer < len) answer = len;	// So that answer can be max value
				}
			}
		}
		// ����
		for (int len = 0; len < 100; len++)
		{
			for (int i = 0; i < 100; i++)
			{
				for (int j = 0; j <= 100 - len; j++)
				{
					check = true;
					for (int k = 0; k < len / 2; k++)
					{
						if (arr[j + k][i] != arr[j + len - 1 - k][i]) {
							check = false;
							break;
						}
					}
					if (check && answer < len) answer = len;	// So that answer can be max value
				}
			}
		}
		// ���
		cout << "#" << Tc << " " << answer << "\n";
	}
	return 0;
}