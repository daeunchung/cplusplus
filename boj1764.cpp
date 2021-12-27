/* push_back X -> 배열 직접 접근*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	vector<string> v1(N);
	vector<string> v2;
	for (int i = 0; i < N; i++) cin >> v1[i];
	sort(v1.begin(), v1.end());	// STL sort 는 quick sort

	string str;
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (binary_search(v1.begin(), v1.end(), str)) {
			v2.emplace_back(str);
		}
	}
	sort(v2.begin(), v2.end());
	cout << v2.size() << '\n';
	for (int i = 0; i < v2.size(); i++) cout << v2[i] << '\n';
	return 0;
}

