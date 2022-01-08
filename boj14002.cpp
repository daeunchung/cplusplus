/*
D[i] = A[1], ..., A[i] ���� ������ ���� ��,  A[i]�� ���������� �ϴ� ���� �� �����ϴ� �κ� ������ ����
V[i] = A[i] �տ� �;� �ϴ� ���� �ε���. ��, A[i]�տ��� A[V[i]]�� �;� ���̰� ���� ���.
=> ��, �κ� ������ ����(������ ���)�� �����ϴ� �迭 v�� �ϳ��� �ξ�� �κ� ���� ������ ��� ����
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
	// d[i] : i���� ������ �κ� ���� �ִ� ����
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}
	// �κ� ������ �ִ� ���� ã�� �κ�
	int max = -1, idx = -1;
	for (int i = 1; i <= n; i++) {
		if (max < d[i]) {
			max = d[i];
			idx = i;
		}
	}
	cout << max << '\n';
	// �κ� ������ ������ ���� ���
	if (find(idx) == -1) {
		while (!s.empty()) {
			cout << s.top() << ' ';
			s.pop();
		}
		cout << '\n';
	}
	return 0;
}

//// �Ʒ��� ���� �ڵ� �Ⱥ��� Ǯ���� �ʹ� ��ڴ�
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