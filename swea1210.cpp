/* 1210. [S/W 문제해결 기본] 2일차 - Ladder1 D4 */
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
5번 제출함 ㅠ
1. visited 배열로 방문여부 따져줬더니 Segment fault
2. dfs 처럼 3방향 for문 쓰면서 모두 탐색했더니 Time exceed ... 다른사람들 Java코드는 잘만 되던데 왜 C++ 은..
3. 좌로 이동시에는 좌만 , 우로 이동시에는 우만 flag 표시해주니 풀림

3. 풀이 참조 출처
y = 99에서 위로 올라가면서 왼쪽과 오른쪽으로 이동할 수 있는 칸이 있는지 확인한다.
이동할 수 있는 가로선이 있다면 이동하면 되는데 한쪽 방향으로만 이동할 수 있다는 것을 주의해주자!
왼쪽으로 이동했으면 왼쪽으로만 가야지 왼쪽 갔다가 오른쪽으로 가면 안된다.
출처: https://woojeenow.tistory.com/entry/SWEA-1210-Ladder1-cJava [유자의 코딩모험]
*/