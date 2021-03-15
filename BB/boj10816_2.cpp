// 2. unordered map 
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m, a, b;
unordered_map <int, int> mmap;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		mmap[a]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b;
		cout << mmap[b] << " ";
	}
}