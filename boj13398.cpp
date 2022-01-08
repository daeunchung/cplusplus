///* 연속합 1912 연속합2 13398
//연속합 2
// =>내가 기존에 하려던 하나의 수씩 삭제해 가면서 최댓값을 구하는 방법은 O(N제곱) 이라 시간초과
// 실제로 배열에서 수를 삭제하지 않고서도 연속합의 최댓값을 구할 수 있다
//*/
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int a[100001], b[100000], d[100000][100000];
//int main()
//{
//	int n;	cin >> n;
//	for (int i = 1; i <= n; i++) cin >> a[i];
//
//	for(int del=1; del <= n; del++)
//	{
//		int k = 1;
//		for (int i = 1; i <= n; i++) {
//			if (i != del) {
//				b[k++] = a[i];
//			}
//		}
//	}
//
//	d[0] = b[0];
//	for (int i = 1; i < n-1; i++)
//		d[i] = max(b[i] + d[i - 1], b[i]);
//	cout << *max_element(d.begin(), d.end()) << '\n';
//	return 0;
//}