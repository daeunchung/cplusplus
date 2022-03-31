/////* 사용할 수 있는 간선에 제한이 생기면 문제 해결을 위해 정점을 분리시킨다
//// next = now*2(2sec) or now-1(1sec)
//// 복사 : (s,c) ->(s,s)
//// 붙여넣기 : (s,c) -> (s+c, c)
//// 삭제 : (s,c) -> (s-1, c)
//// 2<=S<=1000 이라 BFS가능
////
////*** 화면에 이모티콘 S개는 알고있지만 클립보드에 이모티콘이 몇개인지 알 수 없다.***
//// bool check[] + int dist[] 를 하나의 배열 int dist[] 로 표현가능 (-1이면 not visited로)
//// */
////
////
//
//
//// 이모티콘 진짜 어려움 ㅠ
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
////// d[i][0]: i번째 이모티콘 visited 여부 -1==false, 0==true;
////// d[i][1]: i번째 이모티콘이 찍힐 때 clipboard 스티커 갯수
////// d[i][2]: i번째 이모티콘이 만들어지기까지 걸린 time
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
////		// 복사하기
////		if (d[s][s] == -1) {
////			d[s][s] = d[s][c] + 1;
////			q.push(make_pair(s, s));
////		}
////		// 붙여넣기
////
////		// 삭제하기
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
//// 아래가 정답코드
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