#include <iostream>
using namespace std;

int N;

int factorial(int n)
{
	// �Է��� 0�����̱� ������, ���� n == 1�� �� ���, ���ѷ����� ���� �ð��ʰ��� �߻�
	if (n <= 1) return 1;
	else return n * factorial(n - 1);
}
int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);	
	cin >> N;
	cout << factorial(N) << '\n';
	return 0;
}