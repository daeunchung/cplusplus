/* 
1. 플로이드 와샬 알고리즘  
	기본 틀 : 3중 반복문
	가장 바깥쪽 반복문이 중간점 역할, 중간쪽 반복문이 시작점, 가장 안쪽 반복문이 도착점 역할

	케빈 베이컨 게임은 임의의 두 사람이 최소 몇 단계 만에 이어질 수 있는지 계산하는 게임이다.
	=> 출발점에서 중간 지점을 거쳐, 도착점에 갈 수 있는 최소의 방법을 구하는 문제같은 것에는 플로이드 워샬 알고리즘이 가장 좋다
	
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

	/* BOJ의 유저 중에서 케빈 베이컨의 수가 가장 작은 사람을 출력한다. 
	그런 사람이 여러 명일 경우에는 번호가 가장 작은 사람을 출력한다. */
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