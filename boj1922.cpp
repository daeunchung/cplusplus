//// ��Ʈ��ũ ���� :: �׷��� �̷� , �ּҽ��д�Ʈ��(mst minimum spanning tree)
//// ���̵��� ũ�罺Į(����Ž��:���Ͽ����ε� + �켱����ť) < ����(���Ž��:�켱����ť)
//#include <iostream>
//#include <queue>
//using namespace std;
//// n (1 �� n �� 1000)    m (1 �� m �� 100,000)    c (1 �� c �� 10,000) 
//
//int n, m, a, b, c;
//int parent[1001];
//
//// pq �� ������ ����ü�� ���� Ȱ������ - ������ ���δ�
//struct data {
//	int node1, node2, weight;
//	data() {};
//	data(int node1, int node2, int weight) : node1(node1), node2(node2), weight(weight) {};
//
//	// �� ������ �������̵� (pq �� ���Ĺ���� ����)
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
//	// find() �� �����Ͽ� ��ξ���
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