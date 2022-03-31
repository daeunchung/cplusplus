// 소인수분해
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int N;
bool isPrime[10000001];	// false이면 소수
void Erathos()
{
	for (int i = 2; i <= sqrt(10000000); i++) {
		if (isPrime[i]) continue;
		for (int j = i * i; j <= 10000000; j += i) {
			isPrime[j] = true;
		}
	}
}

int nextPrime(int pn)
{
	while (true) {
		if (!isPrime[++pn]) return pn;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(0);	cout.tie(0);
	cin >> N;
	if (N == 1) return 0;

	Erathos();
	
	int div = 2;	// primeNumber
	while (N > 0)
	{
		if (N % div == 0) {
			N /= div;
			cout << div << '\n';
			if (N == 1) break;
		}
		else {
			div = nextPrime(div);
		}
	}
	return 0;
}
