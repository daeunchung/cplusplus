// 1. �ð� ���⵵�� O(1)�� HashMap�� �̿�
// 2. �̺� Ž���� �̿��� Ǯ�̴� Algorithm STL �� lower_bound, upper_bound Ȱ��
// N(1 �� N �� 500,000) �̶� �ϴ� O(N^2) �� ���� ��� �Ұ���
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