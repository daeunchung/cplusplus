/////* ����� �� �ִ� ������ ������ ����� ���� �ذ��� ���� ������ �и���Ų��
//// next = now*2(2sec) or now-1(1sec)
//// ���� : (s,c) ->(s,s)
//// �ٿ��ֱ� : (s,c) -> (s+c, c)
//// ���� : (s,c) -> (s-1, c)
//// 2<=S<=1000 �̶� BFS����
////
////*** ȭ�鿡 �̸�Ƽ�� S���� �˰������� Ŭ�����忡 �̸�Ƽ���� ����� �� �� ����.***
//// bool check[] + int dist[] �� �ϳ��� �迭 int dist[] �� ǥ������ (-1�̸� not visited��)
//// */
////
////
//
//
//// �̸�Ƽ�� ��¥ ����� ��
//
//
/////* DP + bfs(?) */
////#include <bits/stdc++.h>
////#include <iostream>
////#include <queue>
////using namespace std;
//////int d[1001][1001];
////
////int d[1001][3];
////// d[i][0]: i��° �̸�Ƽ�� visited ���� -1==false, 0==true;
////// d[i][1]: i��° �̸�Ƽ���� ���� �� clipboard ��ƼĿ ����
////// d[i][2]: i��° �̸�Ƽ���� ������������ �ɸ� time
////
//////bool visited[1001];
//////int clipboard = 0, t = 0, scr = 1;
//////6 = 1+2+3      1 1 2 2 4 6 => 5     1 1 2 3 3 6 => 5
////
////int main()
////{
////	const int vst = 0, clipb = 1, tiime = 2;
////	int n;	 cin >> n;
////
////	d[1][vst] = 1; d[1][clipb] = 0; d[1][tiime] = 0;
////
////
////	clipboard = 1;	++t;
////	if (scr + clipboard <= n) {
////		d[scr + clipboard] = ++t;
////	}
////
////
////
////
////
////
////	memset(d, -1, sizeof(d));
////	queue<pair<int, int>> q;
////	q.push(make_pair(1, 0));
////	d[1][0] = 0;
////
////	while (!q.empty())
////	{
////		int s, c;
////		tie(s, c) = q.front();
////		q.pop();
////		// �����ϱ�
////		if (d[s][s] == -1) {
////			d[s][s] = d[s][c] + 1;
////			q.push(make_pair(s, s));
////		}
////		// �ٿ��ֱ�
////
////		// �����ϱ�
////		if (now - 1 >= 0)
////		{
////			if (!check[now - 1])
////			{
////				q.push(now - 1);
////				check[now - 1] = true;
////				dist[now - 1] = dist[now] + 1;
////				from[now - 1] = now;
////			}
////		}
////		if (now + 1 < MAX + 1)
////		{
////			if (!check[now + 1])
////			{
////				q.push(now + 1);
////				check[now + 1] = true;
////				dist[now + 1] = dist[now] + 1;
////				from[now + 1] = now;
////			}
////		}
////		if (now * 2 < MAX + 1)
////		{
////			if (!check[now * 2])
////			{
////				q.push(now * 2);
////				check[now * 2] = true;
////				dist[now * 2] = dist[now] + 1;
////				from[now * 2] = now;
////			}
////		}
////	}
////	cout << dist[K] << '\n';
////	print(N, K);
////	cout << '\n';
////	return 0;
////}
//
//
// 
// 
// 
// 
//// �Ʒ��� �����ڵ�
//#include <iostream>
//#include <tuple>
//#include <queue>
//#include <cstring>
//using namespace std;
//int d[1001][1001];
//int main() {
//    int n;
//    cin >> n;
//    memset(d, -1, sizeof(d));
//    queue<pair<int, int>> q;
//    q.push(make_pair(1, 0));
//    d[1][0] = 0;
//    while (!q.empty()) {
//        int s, c;
//        tie(s, c) = q.front();
//        q.pop();
//        if (d[s][s] == -1) {
//            d[s][s] = d[s][c] + 1;
//            q.push(make_pair(s, s));
//        }
//        if (s + c <= n && d[s + c][c] == -1) {
//            d[s + c][c] = d[s][c] + 1;
//            q.push(make_pair(s + c, c));
//        }
//        if (s - 1 >= 0 && d[s - 1][c] == -1) {
//            d[s - 1][c] = d[s][c] + 1;
//            q.push(make_pair(s - 1, c));
//        }
//    }
//    int ans = -1;
//    for (int i = 0; i <= n; i++) {
//        if (d[n][i] != -1) {
//            if (ans == -1 || ans > d[n][i]) {
//                ans = d[n][i];
//            }
//        }
//    }
//    cout << ans << '\n';
//    return 0;
//}