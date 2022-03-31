//// 네트워크 연결 :: 그래프 이론 , 최소스패닝트리(mst minimum spanning tree)
//// 난이도가 크루스칼(간선탐색:유니온파인드 + 우선순위큐) < 프림(노드탐색:우선순위큐)
//#include <iostream>
//#include <queue>
//using namespace std;
//// n (1 ≤ n ≤ 1000)    m (1 ≤ m ≤ 100,000)    c (1 ≤ c ≤ 10,000) 
//
//int n, m, a, b, c;
//int parent[1001];
//
//// pq 를 쓸때는 구조체를 적극 활용하자 - 김형우 프로님
//struct data {
//	int node1, node2, weight;
//	data() {};
//	data(int node1, int node2, int weight) : node1(node1), node2(node2), weight(weight) {};
//
//	// 비교 연산자 오버라이딩 (pq 의 정렬방식을 저장)
//	bool operator<(const data d) const {
//		return weight > d.weight;
//	}
//};
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
//// with kruskal's algorithm
//int main()
//{
//	ios_base::sync_with_stdio(false);	cin.tie(0);
//	int n, m, a, b, c;
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> a >> b >> c;
//
//	}
//	priority_queue<int> pq;
//
//	return 0;
//}