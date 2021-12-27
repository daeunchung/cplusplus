/* 1210. [S/W �����ذ� �⺻] 2���� - Ladder1 D4 */
#include <iostream>
#include <string.h>
using namespace std;
int arr[100][100];
int check[100][3];	// [i][0] : �����, [i][1] : ������, [i][2] : �̵��Ÿ�
int testCase = 10, x, y, answer;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int Tc = 1; Tc <= testCase; Tc++)
	{
		answer = 0;
		for (int i = 0; i < 100; i++) memset(check[i], 0, sizeof(int) * 3);
		// Input ����
		cin >> Tc;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
				if (i == 0 && arr[i][j] == 1)
				{
					check[j][0] = 1;
				}
			}
		}
		int min = 1247000000;
		// �ִ� ��� ���ϱ�
		for (int i = 0; i < 100; i++) {
			if (check[i][0] == 1) 
			{
				y = 0;	x = i;
				int count = 1;
				while (y < 99)
				{
					bool flag = false;
					while (x + 1 < 100 && arr[y][x + 1])
					{
						flag = true;
						x++;	count++;
					}
					if (!flag) {
						while (x - 1 >= 0 && arr[y][x - 1]) {
							x--;	count++;
						}
					}
					y++;	count++;
				}
				check[i][1] = x;	// ������
				check[i][2] = count;// ����� ����
				if (min >= count) {
					min = count;
					answer = i;
				}
			}
		}
		cout << "#" << Tc << " " << answer << "\n";
	}
	return 0;
}
