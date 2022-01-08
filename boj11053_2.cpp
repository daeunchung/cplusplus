/* LIS Longest Increasing Subsequence
D[i] = A[1], ... A[i] 까지 수열이 있을 때, A[i]을 마지막으로 하는 가장 긴 증가하는 부분 수열의 길이
D[i] = max(D[j]) + 1 (j < i, A[j] < A[i])
여태 푼 문제들과 다르게 n = 6일때 D[6] 이 답이 아닐 수도있다. 전체 D[i]의 값 중에 최대값이 정답이 된다
=> O(N제곱)
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> d(n, 1);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[j] < a[i] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
	cout << *max_element(d.begin(), d.end()) << '\n';
	return 0;
}
