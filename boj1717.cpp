//// 대표적인 Union Find 예제
//// 알고리즘 : 자료구조, 분리집합(disjoint set)
//#include <iostream>
//using namespace std;
//
//int n, m;
//int cmd, a, b;
//int parent[10000001];
//
//int find(int x)
//{
//	if (parent[x] == x) return x;
//	return parent[x] = find(parent[x]);
//}
//
//void uni(int x, int y)
//{
//	// find() 를 포함하여 경로압축
//	parent[find(x)] = find(y);
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);	cin.tie(0);
//	cin >> n >> m;
//	for (int i = 0; i <= n; i++)
//		parent[i] = i;
//
//	for (int i = 0; i < m; i++)
//	{
//		cin >> cmd >> a >> b;
//		if (cmd == 0) uni(a, b);
//		else {
//			if (find(a) == find(b))
//				cout << "YES\n";
//			else
//				cout << "NO\n";
//		}
//	}
//	return 0;
//}