///* BFS -> Queue 가 필요 . 잊지말자
//
//나는 처음에 cnt 변수를 BFS 재귀하면서 증가시키는걸로 잘못 짰었음. */
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int M, N;
//int T[1001][1001];	// 순회하면서 흐르는 시간을 동적으로 누적시켜 기록할 배열 (즉, 최댓값이 총 걸리는 시간)
//queue<pair<int, int>> q;
//
//int dy[4] = { 1, 0, -1, 0 };
//int dx[4] = { 0, 1, 0 , -1 };
//
//void BFS()
//{
//	while (!q.empty()) {
//		int y = q.front().first;
//		int x = q.front().second;
//
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int yy = y + dy[i];
//			int xx = x + dx[i];
//
//			if (yy <= 0 || yy > N || xx <= 0 || xx > M) continue;
//			if (T[yy][xx] == 0) {
//				T[yy][xx] = T[y][x] + 1;
//				q.push(make_pair(yy, xx));
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> M >> N;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			cin >> T[i][j];
//			if (T[i][j] == 1) q.push(make_pair(i, j));	// 익은 토마토만 큐에 넣는다.
//		}
//	}
//	BFS();
//
//	/* 날짜 계산 및 출력 */
//	int cnt = 0;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			// 익지않은 토마토(0)가 존재할 경우
//			if (T[i][j] == 0) {
//				cout << -1 << '\n';
//				return 0;
//			}
//			// 최댓값 찾기
//			if (cnt < T[i][j]) {
//				cnt = T[i][j];
//			}
//		}
//	}
//	cout << cnt-1 << '\n';
//	return 0;
//}