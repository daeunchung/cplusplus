/* 
1. �÷��̵� �ͼ� �˰���  
	�⺻ Ʋ : 3�� �ݺ���
	���� �ٱ��� �ݺ����� �߰��� ����, �߰��� �ݺ����� ������, ���� ���� �ݺ����� ������ ����

	�ɺ� ������ ������ ������ �� ����� �ּ� �� �ܰ� ���� �̾��� �� �ִ��� ����ϴ� �����̴�.
	=> ��������� �߰� ������ ����, �������� �� �� �ִ� �ּ��� ����� ���ϴ� �������� �Ϳ��� �÷��̵� ���� �˰����� ���� ����
	
2. BFS / DFS 

*/
#include <iostream>
#include <algorithm>
using namespace std;

int dy[101][101];	// dynamic table

int main() {
	int N, M, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		dy[a][b] = dy[b][a] = 1;
	}

	// Floyd Warshall
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				else if (dy[i][k] && dy[k][j]) {
					if (dy[i][j] == 0) dy[i][j] = dy[i][k] + dy[k][j];
					else dy[i][j] = min(dy[i][j], dy[i][k] + dy[k][j]);
				}
			}
		}
	}

	/* BOJ�� ���� �߿��� �ɺ� �������� ���� ���� ���� ����� ����Ѵ�. 
	�׷� ����� ���� ���� ��쿡�� ��ȣ�� ���� ���� ����� ����Ѵ�. */
	int user = 0, min = 2147000000;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			cnt += dy[i][j];
		}
		if (cnt < min) {
			min = cnt;	user = i; 
		}
	}
	cout << user << '\n';
	return 0;
}