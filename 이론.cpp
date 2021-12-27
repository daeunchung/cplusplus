/*
���� - ������ ����
�������信�� ������ ������� X, �������� ������ ������ ���� ����O
���ϱ�� ���ϱ��� �����̶� ���� ����
(A + B)mod M = ((A mod M) + (B mod M)) mod M
(A * B)mod M = ((A mod M) * (B mod M)) mod M
(A - B)mod M = ((A mod M) - (B mod M) + M) mod M

���� - �ִ����� GCD (1.�׳�, 2.��Ŭ����ȣ����)


���� - �ּҰ���� LCM
A * B = GCD * LCM �� �̿�

���� - �Ҽ� �˰��� 2��
1. � �� N �� �Ҽ� ���� �Ǻ�
2. N���� �۰ų� ���� ��� �ڿ��� �� �Ҽ� ã��


dp - Top down ���ȣ��
dp - Bottom up �ݺ���

*/

int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int gcdEuclid(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

bool prime1(int n) 
{
	if (n < 2) return false;
	for (int i = 2; i <= n - 1; i++) {
		if (n % i == 0) return false;
	}
	return true;
} // => O(N)

// N�� ��� �߿��� ���� ū ���� N/2���� �۰ų� ���� ������ ���� ����
bool prime2(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= n/2; i++) {
		if (n % i == 0) return false;
	}
	return true;
} // => O(N/2) = O(N)

// ���� ���� : ��ǻ�Ϳ��� �Ǽ��� �ٻ簪�̱⿡ i*i<=n ǥ���� ����
bool prime3(int n)
{
	if (n < 2) return false;
	for (int i = 2; i*i<=n; i++) {
		if (n % i == 0) return false;
	}
	return true;
} // => O(��ƮN)

/* �����佺�׳׽��� ü Sieve of Eratosthenes (�Ҽ����ϱ� �˰��� �߿� ���� �߿� ���� �߿� �ſ� �߿�)
  => O(NloglogN) for��N�� * if��(loglogN���������)
  ����for���� j �� N�� ũ�⿡ ����, i*i �Ǵ� i*2 �� �ٲٴ� ���� ����.
  �ֳ��ϸ� i=�鸸�� ��� i*i�� 1���� �Ǵµ� int�� 2�鸸���� ���� �̱� ����

  ��� �Ҽ��� 6n+1�Ǵ� 6n+5 �� ���� ���.
*/
void Eratosthenes()
{
	int prime[100];	// �Ҽ� ����
	int pn = 0;		// �Ҽ��� ����
	bool check[101];	// ���������� true(�Ҽ��� �ƴϴ�), ���������� false(�Ҽ�)
	int n = 100;
	for (int i = 2; i <= n; i++)
	{
		if (check[i] == false)	// �������� �ʾ�����
		{
			prime[pn++] = i;
			for (int j = i * i; j <= n; j += i) {
				check[j] = true;
			}
		}
	}
} //=> O(NloglogN) for��N�� * if��(loglogN���������)

/* �������� ���� Goldbach's conjecture 
2 ���� ū ��� ¦���� �� �Ҽ��� ������ ǥ���� �����ϴ�. --+3--> 5���� ū ��� Ȧ���� �� �Ҽ��� ������ ǥ�� �����ϴ�.
check[N-b] == false ���� Ȯ��
*/

/* ���丮�� Factorial �θ�Ʈ������ �߿� 10!=3�鸸, 20!=int�������
 nCm = n!/((n-m)!m!) : 2�� ���� > 5�� ���� �� �� �� �ֱ⿡ �Ѵ� ����� �� �������� ���� �˾ƾ���
*/