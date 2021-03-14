//#include <iostream>
//#include <vector>
//using namespace std;
//int main() {
//	ios_base::sync_with_stdio(false);	cin.tie(NULL);
//	int n, k;
//	cin >> n >> k;
//	vector<int> v(n, n);
//	vector<int>::iterator iter;
//	for (int i = 1; i < n; i++) v[i] = i;
//
//	cout << "<";
//	iter = v.begin();
//	while (!v.empty()) {
//		for (int i = 0; i < k; i++) {
//			iter++;
//			if (iter == v.end()) iter = v.begin();
//		}
//		cout << *iter;
//		if(v.size() > 1) cout << ", ";
//		iter = v.erase(iter);
//	}
//	cout << ">";
//	return 0;
//}