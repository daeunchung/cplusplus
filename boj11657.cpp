/*
11657 ���� ������ �����ϴ� �׷��� - �������� �˰�����
 ���ͽ�Ʈ�� O(ElogV) �� ���ǰ��� ������ ��� �Ұ���,  ������Ʈ O(VE) ���ǰ��� �ִ°�� ��� ����

 V�� �����̶�� �� �� ����-���� �˰����򿡼��� V-1���� �ݺ����� �������� �ִ� �Ÿ��� �ϼ��˴ϴ�. 
 �׸��� ���⼭ �ݺ����� �ѹ� �� ������ �� �ִܰŸ��� ������ �ȴٸ� ���� ����Ŭ�� �����Ѵٴ� �ǹ��̹Ƿ�
 i�� N�� �� �ִܰŸ��� ���ŵ� �ÿ� bool�� ������ cycle�� true�� �����մϴ�.

 �ִܰ�� �˰������� ũ�� ���ͽ�Ʈ��� ����-���� �˰����� �� ������ �ֽ��ϴ�. 
 ���ͽ�Ʈ�� �˰������� ���� ����ġ�� ������ ��� �������� �ʽ��ϴ�. 
 ����-���� �˰������� ��� ���� ����ġ�� �������� �����ϳ�, negative cycle�� ���� ��� �������� �ʽ��ϴ�. 
 ���ͽ�Ʈ�� �˰������� ��꺹�⼺�� O(|V|2+|E|)�̸�, ����-����� O(|V||E|)�Դϴ�.
 ��ü��(All-pair) �ִܰ�� ������ Floyd-Warshall �˰������� �θ� ���δٰ� �մϴ�
 �ٸ� ��尡 �ٸ��ٸ� ���Ͻ� �ִܰ�� ������ ���� �������̱� ������, 
 �ֱٿ� ���Ͻ� ������ ������ ���ͽ�Ʈ��/����-���� �˰������� GPU�� Ȱ���� 
 ����ó���ϴ� ������� ��ü�� �ִܰ�θ� Ǫ�� ��찡 ���ٰ� �մϴ�.

 ������ ���� N (1 �� N �� 500), ���� �뼱�� ���� M (1 �� M �� 6,000)
 M���� �ٿ��� ���� �뼱�� ���� A, B, C (1 �� A, B �� N, -10,000 �� C �� 10,000)
 */
//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
//#define INF 2100000000	// 21��
//
//// ���� ����Ʈ
//vector<pair<int, int>> v[501];
//int N, M, A, B, C, a, b;
//long long dist[501];
//
//int main()
//{
//	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
//	cin >> N >> M;	// ������ >> ������
//	for (int i = 0; i < M; i++)
//	{
//		cin >> A >> B >> C;
//		v[A].push_back({ B,C });
//	}
//
//	for (int i = 1; i <= N; i++)
//		dist[i] = INF; // ��� ��带 INF�� ����
//
//	return 0;
//}