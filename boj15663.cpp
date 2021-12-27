//#include <iostream>
//#include <vector>
//#include <algorithm>
//#define MAX 9
//using namespace std;
//
//int n, m;
//int arr[MAX];
//vector<int> v;
//bool visited[MAX];
///* 흠......................... 다시해봐 아직 로직 안봤고 이건 틀린듯*/
//void dfs(int idx, int cnt)
//{
//	if (cnt == m)
//	{
//		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
//		cout << '\n';
//		return;
//	}
//	for (int i = 0; i < v.size(); i++)
//	{
//		if (!visited[i]) 
//		{
//			visited[i] = true;
//			arr[cnt] = v[i];
//			dfs(i, cnt + 1);
//			visited[i] = false;
//		}
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(NULL);	cin.tie(NULL);
//	cin >> n >> m;
//	v.resize(n);
//	for (int i = 0; i < n; i++)	cin >> v[i];
//	sort(v.begin(), v.end());
//	unique(v.begin(), v.end());
//
//	dfs(0, 0);
//
//	return 0;
//}