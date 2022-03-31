// 1. 시간 복잡도가 O(1)인 HashMap을 이용
// 2. 이분 탐색을 이용한 풀이는 Algorithm STL 의 lower_bound, upper_bound 활용
// N(1 ≤ N ≤ 500,000) 이라서 일단 O(N^2) 은 절대 통과 불가능
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

//unordered_map <int, int> m;
//int N, M, x;
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> x;
//		m[x] += 1;
//	}
//	cin >> M;
//	for (int i = 0; i < M; i++) {
//		cin >> x;
//		cout << m[x] << " ";
//	}
//	return 0;
//}

int arr[500001];
int N, M, x;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> x;
		cout << upper_bound(arr, arr + N, x) - lower_bound(arr, arr + N, x) << ' ';
	}
	return 0;
}