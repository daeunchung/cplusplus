///* ������ 1912 ������2 13398
//������ 2
// =>���� ������ �Ϸ��� �ϳ��� ���� ������ ���鼭 �ִ��� ���ϴ� ����� O(N����) �̶� �ð��ʰ�
// ������ �迭���� ���� �������� �ʰ��� �������� �ִ��� ���� �� �ִ�
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