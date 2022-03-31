//// 행렬 곱셈 순서
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

// 위에서 문제를 잘못 파악해서 연산 종류를 처음~끝, 끝~처음 이렇게 두가지의 값만 비료하였음
//0 ~ N-1 까지의 행렬의 곱을 구한다고 가정했을 때, 
//0 ~ k, k+1 ~ N-1의 두 가지 경우로 나누어 곱셈 연산의 수를 비교해보자.