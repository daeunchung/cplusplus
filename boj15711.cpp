// ȯ���� ¦�� - �����佺�׳��� ü  T(1 �� T �� 500) ,  (1 �� A, B �� 2 �� 10^12)
// A + B <= 4 * 10^12
// �����佺�׳׽��� ü�� ����Ͽ� �������� 2 * 10^6 ������ �Ҽ����� ã�� 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
long long a, b, s;
bool sieve[2000001];	// false �� �ʱ�ȭ
vector<int> v;			// �Ҽ� ����� ����

void eratos()
{
	sieve[1] = true;
	for (int i = 2; i <= 2000000; i++)
	{
		if (!sieve[i]) {
			v.push_back(i);
			for (int j = i + i; j <= 2000000; j += i) {
				sieve[j] = true;
			}
		}
	}
}

bool isPrime(long long x)
{
	if (x <= 2000000) return !sieve[x];
	for (int i = 0; i < v.size(); i++){
		if (s % v[i] == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	
	// �����佺�׳׽��� ü
	eratos();

	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		s = a + b;

		if (s == 2 || s == 3) {
			cout << "NO" << '\n';
		}
		// �������� ���� (¦ = Ȧ�Ҽ� + Ȧ�Ҽ�) ������ ����
		else if (s % 2 == 0) {
			cout << "YES" << '\n';
		}
		// Ȧ = ¦(2) + Ȧ�Ҽ�
		else {
			s -= 2;
			if(isPrime(s)) 
				cout << "YES" << '\n';
			else 
				cout << "NO" << '\n';
		}
	}
	return 0;
}