/*
 �Ϲ� ��� ���� �ð��ʰ� �߻� 
 DP ���� Memoization �� �迭�� ���� �����ؾ���
*/
#include <iostream>
using namespace std;
int arr[50] = { 0,1, };

int fibo(int N)
{
	if (N == 0 || N == 1)
		return arr[N];
	else if (arr[N] == 0)
		arr[N] = fibo(N - 1) + fibo(N - 2);
	return arr[N];
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int n, tmp;
	cin >> n;
	for (; n--;) {
		cin >> tmp;
		if (tmp == 0) cout << "1 0" << '\n';
		else cout << fibo(tmp - 1) << ' ' << fibo(tmp) << '\n';
	}
	return 0;
}