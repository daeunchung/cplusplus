/* 1210. [S/W �����ذ� �⺻] 2���� - Ladder1 D4 */
#include <iostream>
using namespace std;
int arr[100][100];
int testCase = 10, x, y;
int dy[] = { 0, 0, -1 };
int dx[] = { -1, 1, 0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int Tc = 1; Tc <= testCase; Tc++)
	{
		cin >> Tc;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 2)
				{
					x = j;
				}
			}
		}
		y = 99;
		while (y != 0)
		{
			bool flag = false;

			while (x + 1 < 100 && arr[y][x + 1])
			{
				flag = true;
				x++;
			}
			if (!flag) {
				while (x - 1 >= 0 && arr[y][x - 1]) x--;
			}
			y--;
		}
		cout << "#" << Tc << " " << x << "\n";
	}
	return 0;
}

/*
5�� ������ ��
1. visited �迭�� �湮���� ��������� Segment fault
2. dfs ó�� 3���� for�� ���鼭 ��� Ž���ߴ��� Time exceed ... �ٸ������ Java�ڵ�� �߸� �Ǵ��� �� C++ ��..
3. �·� �̵��ÿ��� �¸� , ��� �̵��ÿ��� �츸 flag ǥ�����ִ� Ǯ��

3. Ǯ�� ���� ��ó
y = 99���� ���� �ö󰡸鼭 ���ʰ� ���������� �̵��� �� �ִ� ĭ�� �ִ��� Ȯ���Ѵ�.
�̵��� �� �ִ� ���μ��� �ִٸ� �̵��ϸ� �Ǵµ� ���� �������θ� �̵��� �� �ִٴ� ���� ����������!
�������� �̵������� �������θ� ������ ���� ���ٰ� ���������� ���� �ȵȴ�.
��ó: https://woojeenow.tistory.com/entry/SWEA-1210-Ladder1-cJava [������ �ڵ�����]
*/