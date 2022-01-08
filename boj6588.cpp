// 21-12-27 
// �����佺�׳׽��� ü�� ��ƮN ���ʿ� X, check[N-b] == false �� �Ҽ��� ���ϱ⿡ �̰͸� üũ�ϸ� �ȴ�
#include <iostream>
using namespace std;
const int MAX = 1000000;
int prime[MAX];
int pn;	// prime ����
bool check[MAX + 1];	// �Ҽ� �ƴϸ� true��
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	// �����佺�׳׽��� ü�� �ѹ� ����
	for (int i = 2; i * i <= MAX; i++)
	{
		if (check[i] == false) {
			prime[pn++] = i;
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i < pn; i++)
		{
			if (check[n - prime[i]] == false)
			{
				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
				break;
			}
		}
	}
	return 0;
}