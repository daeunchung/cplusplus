//// ��� ���� ����
//#include <iostream>
//#include <algorithm>
//using namespace std;
////int arr[501][2];
//int front1, front2, rear1, rear2;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	int n, a, b, ans = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i++) 
//	{
//		cin >> a >> b;
//		if (i == 1) {
//			front1 = a;	front2 = b;
//			continue;
//		}
//		if (i == n) {
//			rear1 = a;	rear2 = b;
//			continue;
//		}
//		ans += a * b;
//	}
//	int f = front1 * (ans + rear1 * rear2);
//	int r = rear2 * (ans + front1 * front2);
//	cout << min(f,r) << '\n';
//	return 0;
//}

// ������ ������ �߸� �ľ��ؼ� ���� ������ ó��~��, ��~ó�� �̷��� �ΰ����� ���� ����Ͽ���
//0 ~ N-1 ������ ����� ���� ���Ѵٰ� �������� ��, 
//0 ~ k, k+1 ~ N-1�� �� ���� ���� ������ ���� ������ ���� ���غ���.