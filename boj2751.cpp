#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) cout << a[i] << '\n';
	return 0;
}
// �ٸ�������� mergesort O(nlogn) �� ���� �����Ͽ� Ǯ����