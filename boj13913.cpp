///* ��° �ٿ� ��� �̵��ؾ� �ϴ��� �������� ������ ����Ѵ�.
//1697 �� + ��ε� ��� �� ����
//from�迭�� �߰��Ͽ� ������ ��� ������ ���ƴ��� ������ָ� �ȴ�
//*/
//#include <iostream>
//#include <queue>
//using namespace std;
//const int MAX = 200000;	// ���ش��� �̷��� ��µ� ������ �˰����
////const int MAX = 100000;
//bool check[MAX + 1];
//int dist[MAX + 1];
//int from[MAX + 1];
//
//void print(int n, int m)
//{
//	if (n != m) print(n, from[m]);
//	cout << m << ' ';
//}
//
//int main()
//{
//	int N, K;
//	cin >> N >> K;
//	check[N] = true;
//	dist[N] = 0;
//	queue<int> q;
//	q.push(N);
//	while (!q.empty())
//	{
//		int now = q.front();
//		q.pop();
//
//		if (now - 1 >= 0)
//		{
//			if (!check[now - 1])
//			{
//				q.push(now - 1);
//				check[now - 1] = true;
//				dist[now - 1] = dist[now] + 1;
//				from[now - 1] = now;
//			}
//		}
//		if (now + 1 < MAX + 1)
//		{
//			if (!check[now + 1])
//			{
//				q.push(now + 1);
//				check[now + 1] = true;
//				dist[now + 1] = dist[now] + 1;
//				from[now + 1] = now;
//			}
//		}
//		if (now * 2 < MAX + 1)
//		{
//			if (!check[now * 2])
//			{
//				q.push(now * 2);
//				check[now * 2] = true;
//				dist[now * 2] = dist[now] + 1;
//				from[now * 2] = now;
//			}
//		}
//	}
//	cout << dist[K] << '\n';
//	print(N, K);
//	cout << '\n';
//	return 0;
//}
