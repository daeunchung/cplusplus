/*
D[i] = A[1], ..., A[i] 까지 수열이 있을 때,  A[i]을 마지막으로 하는 가장 긴 증가하는 부분 수열의 길이
V[i] = A[i] 앞에 와야 하는 수의 인덱스. 즉, A[i]앞에는 A[V[i]]가 와야 길이가 가장 길다.
=> 즉, 부분 수열의 꼬리(마지막 노드)를 추적하는 배열 v를 하나더 두어야 부분 수열 내용을 출력 가능
*/
#include <iostream>
#include <stack>
using namespace std;

int a[1001];
int d[1001];
int v[1001];
stack<int> s;

int find(int p)
{
	if (p == 0) return -1;
	else {
		s.push(a[p]);
		return find(v[p]);
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	// d[i] : i에서 끝나는 부분 수열 최대 길이
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}
	// 부분 수열의 최대 길이 찾는 부분
	int max = -1, idx = -1;
	for (int i = 1; i <= n; i++) {
		if (max < d[i]) {
			max = d[i];
			idx = i;
		}
	}
	cout << max << '\n';
	// 부분 수열의 내용을 내용 출력
	if (find(idx) == -1) {
		while (!s.empty()) {
			cout << s.top() << ' ';
			s.pop();
		}
		cout << '\n';
	}
	return 0;
}

//// 아래는 정답 코드 안보고 풀었어 너무 기쁘다
//#include <iostream>
//using namespace std;
//int a[1000];
//int d[1000];
//int v[1000];
//void go(int p) {
//	// ? -> ? -> ... a[v[p]] -> a[p]
//	// ---------------------
//	//        go(v[p]);
//	if (p == -1) {
//		return;
//	}
//	go(v[p]);
//	cout << a[p] << ' ';
//}
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	for (int i = 0; i < n; i++) {
//		d[i] = 1;
//		v[i] = -1;
//		for (int j = 0; j < i; j++) {
//			if (a[j] < a[i] && d[i] < d[j] + 1) {
//				d[i] = d[j] + 1;
//				v[i] = j;
//			}
//		}
//	}
//	int ans = d[0];
//	int p = 0;
//	for (int i = 0; i < n; i++) {
//		if (ans < d[i]) {
//			ans = d[i];
//			p = i;
//		}
//	}
//	cout << ans << '\n';
//	go(p);
//	cout << '\n';
//	return 0;
//}