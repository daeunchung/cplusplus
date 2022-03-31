// 환상의 짝꿍 - 에리토스테네의 체  T(1 ≤ T ≤ 500) ,  (1 ≤ A, B ≤ 2 × 10^12)
// A + B <= 4 * 10^12
// 에라토스테네스의 체를 사용하여 제곱근인 2 * 10^6 까지의 소수들을 찾아 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
long long a, b, s;
bool sieve[2000001];	// false 로 초기화
vector<int> v;			// 소수 저장용 벡터

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
	
	// 에라토스테네스의 체
	eratos();

	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		s = a + b;

		if (s == 2 || s == 3) {
			cout << "NO" << '\n';
		}
		// 골드바흐의 추측 (짝 = 홀소수 + 홀소수) 무조건 가능
		else if (s % 2 == 0) {
			cout << "YES" << '\n';
		}
		// 홀 = 짝(2) + 홀소수
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