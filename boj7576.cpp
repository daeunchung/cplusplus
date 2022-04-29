///* BFS -> Queue �� �ʿ� . ��������
//
//���� ó���� cnt ������ BFS ����ϸ鼭 ������Ű�°ɷ� �߸� ®����. */
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int M, N;
//int T[1001][1001];	// ��ȸ�ϸ鼭 �帣�� �ð��� �������� �������� ����� �迭 (��, �ִ��� �� �ɸ��� �ð�)
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
//			if (T[i][j] == 1) q.push(make_pair(i, j));	// ���� �丶�丸 ť�� �ִ´�.
//		}
//	}
//	BFS();
//
//	/* ��¥ ��� �� ��� */
//	int cnt = 0;
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= M; j++) {
//			// �������� �丶��(0)�� ������ ���
//			if (T[i][j] == 0) {
//				cout << -1 << '\n';
//				return 0;
//			}
//			// �ִ� ã��
//			if (cnt < T[i][j]) {
//				cnt = T[i][j];
//			}
//		}
//	}
//	cout << cnt-1 << '\n';
//	return 0;
//}