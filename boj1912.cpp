///* 연속합 1912 연속합2 13398 */
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> a(n);
//	vector<int> d(n, 0);
//	for (int i = 0; i < n; i++) cin >> a[i];
//	d[0] = a[0];
//	for (int i = 1; i < n; i++)
//		d[i] = max(a[i] + d[i - 1], a[i]);
//	cout << *max_element(d.begin(), d.end()) << '\n';
//	return 0;
//}